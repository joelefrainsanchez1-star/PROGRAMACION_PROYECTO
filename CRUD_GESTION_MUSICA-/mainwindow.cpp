#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <sstream>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/new/prefix1/icons/icono_musica2.ico"));

    ui->stackedWidget->setCurrentIndex(0);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(
        {" ID ", " Nombre ", " Artista ", " Género ", " Duración "}
        );

    cargarArchivo();
    mostrarTabla();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// archivoss
void MainWindow::cargarArchivo() {
    canciones.clear();
    ifstream file("music.txt");
    string linea;

    while (getline(file, linea)) {
        stringstream ss(linea);
        Cancion c;
        string aux;

        getline(ss, aux, ';'); c.id = stoi(aux);
        getline(ss, c.nombre, ';');
        getline(ss, c.artista, ';');
        getline(ss, c.genero, ';');
        getline(ss, c.duracion, ';');

        canciones.push_back(c);
    }
}

void MainWindow::guardarArchivo() {
    ofstream file("music.txt");
    for (auto c : canciones) {
        file << c.id << ";"
             << c.nombre << ";"
             << c.artista << ";"
             << c.genero << ";"
             << c.duracion << "\n";
    }
}

//entrada y salida
void MainWindow::on_btnEntrar_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnSalir_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


//tabla
void MainWindow::mostrarTabla() {
    ui->tableWidget->setRowCount(canciones.size());

    for (int i = 0; i < canciones.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(canciones[i].id)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(canciones[i].nombre)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(canciones[i].artista)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(canciones[i].genero)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(canciones[i].duracion)));
    }
}

void MainWindow::on_btnMostrar_clicked()
{
    cargarArchivo();
    mostrarTabla();
}

//crud y funciones
void MainWindow::on_btnAgregar_clicked() {
    Cancion c;
    c.id = canciones.empty() ? 1 : canciones.back().id + 1;

    c.nombre   = ui->txtNombre->text().toStdString();
    c.artista  = ui->txtArtista->text().toStdString();
    c.genero   = ui->txtGenero->text().toStdString();
    c.duracion = ui->txtDuracion->text().toStdString();

    canciones.push_back(c);
    guardarArchivo();
}

void MainWindow::on_btnEliminar_clicked() {
    int fila = ui->tableWidget->currentRow();
    if (fila < 0) return;

    canciones.erase(canciones.begin() + fila);
    guardarArchivo();
    mostrarTabla();
}

void MainWindow::on_btnEditar_clicked() {
    int fila = ui->tableWidget->currentRow();
    if (fila < 0) return;

    canciones[fila].nombre   = ui->txtNombre->text().toStdString();
    canciones[fila].artista  = ui->txtArtista->text().toStdString();
    canciones[fila].genero   = ui->txtGenero->text().toStdString();
    canciones[fila].duracion = ui->txtDuracion->text().toStdString();

    guardarArchivo();
    mostrarTabla();
}
