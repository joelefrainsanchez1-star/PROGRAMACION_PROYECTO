#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QString>
#include <fstream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
//----------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//----------------------------------------------------------------
void MainWindow::on_btnIngresar_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // menú
}
//----------------------------------------------------------------
void MainWindow::on_btnSalir_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // inicio
}
//----------------------------------------------------------------
void MainWindow :: ingresarDatosTabla(vector <cancion> &c){
    size_t numeroColumna = c.size();
    for (int fila = 0; fila < c.size(); fila++){
        for (int columna = 0; columna < 5; columna++){
            switch (columna){
            case 0:
                QTableWidgetItem *campo = new QTableWidgetItem (QString :: fromStdString(c[fila].id));
                ui -> tableWidget -> setItem(fila, columna, campo);
                break;
            case 1:
                QTableWidgetItem *campo = new QTableWidgetItem (QString :: fromStdString(c[fila].nombre));
                ui -> tableWidget -> setItem(fila, columna, campo);
                break;
            case 2:
                QTableWidgetItem *campo = new QTableWidgetItem (QString :: fromStdString(c[fila].artista));
                ui -> tableWidget -> setItem(fila, columna, campo);
                break;
            case 3:
                QTableWidgetItem *campo = new QTableWidgetItem (QString :: fromStdString(c[fila].genero));
                ui -> tableWidget -> setItem(fila, columna, campo);
                break;
            case 4:
                QTableWidgetItem *campo = new QTableWidgetItem (QString :: fromStdString(c[fila].duracion));
                ui -> tableWidget -> setItem(fila, columna, campo);
                break;
            }
        }
    }
}
//----------------------------------------------------------------
void MainWindow::on_buttonAgregar_clicked(vector <cancion> &c){
    int id;
    cancion nuevaCancion;
    QString nombreCancion = ui -> txtNombre -> text();
    QString artista = ui -> txtArtista -> text();
    QString duracion = ui -> txtDuracion -> text();
    QString genero = ui -> txtGenero -> text();
    nuevaCancion.nombre = nombreCancion;
    nuevaCancion.artista = artista;
    nuevaCancion.duracion = duracion;
    nuevaCancion.genero = genero;
    actualizarIDs(c);
    nuevaCancion.id = (c.size()) + 1;
    c.push_back(nuevaCancion);
    ingresarDatosTabla(c);
}
//----------------------------------------------------------------
void MainWindow::on_buttonMostrar_clicked()
{

}

