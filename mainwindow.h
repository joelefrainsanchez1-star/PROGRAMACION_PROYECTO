#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct cancion {
    int id;
    std::string nombre;
    std::string artista;
    std::string genero;
    std::string duracion;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnIngresar_clicked();
    void on_btnSalir_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<cancion> canciones;
};

#endif
