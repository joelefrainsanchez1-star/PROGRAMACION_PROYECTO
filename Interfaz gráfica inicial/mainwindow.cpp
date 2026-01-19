#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->titulo->setText("S I S T E M A    D E    M U S I C A");
    ui->subtitulo->setText("Bienvenido al sistema");
    ui->botonIngresar->setText("Ingresar");
    ui->botonSalir->setText("Salir");
}

MainWindow::~MainWindow()
{
    delete ui;

}
