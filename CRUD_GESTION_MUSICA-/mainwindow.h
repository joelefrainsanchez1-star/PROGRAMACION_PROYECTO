#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Cancion {
    int id;
    string nombre;
    string artista;
    string genero;
    string duracion;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnEntrar_clicked();
    void on_btnAgregar_clicked();
    void on_btnEliminar_clicked();
    void on_btnEditar_clicked();

private:
    Ui::MainWindow *ui;
    vector<Cancion> canciones;

    void cargarArchivo();
    void guardarArchivo();
    void mostrarTabla();
};

#endif
