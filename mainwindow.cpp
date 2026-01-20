#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnIngresar_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // menú
}

void MainWindow::on_btnSalir_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // inicio
}
