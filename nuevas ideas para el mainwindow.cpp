//-----------------
codigo para boton agregar
//---------------------------------------------------------------------------
void MainWindow::on_btnAgregar_clicked() {
    Cancion c;
    int validador = 0;
    c.id = canciones.empty() ? 1 : canciones.back().id + 1;
    c.nombre   = ui->txtNombre->text().toStdString();
    c.artista  = ui->txtArtista->text().toStdString();
    c.genero   = ui->txtGenero->text().toStdString();
    c.duracion = ui->txtDuracion->text().toStdString();
    if (c.artista.empty() ||
        c.duracion.empty() ||
        c.genero.empty() ||
        c.nombre.empty())
    {
        QMessageBox :: warning(this,"Error","Debe llenar todos los campos");
    }else {
        canciones.push_back(c);
        guardarArchivo();
        ui -> txtNombre -> clear();
        ui -> txtArtista -> clear();
        ui -> txtGenero -> clear();
        ui -> txtDuracion -> clear();
    }
//---------------------------------------------------------------------------
// boton para que la funcion editar, tome en cuenta solo las casillas llenas
void MainWindow::on_btnEditar_clicked() {
    int fila = ui->tableWidget->currentRow();
    if (fila < 0) return;
    if (!(ui -> txtNombre -> text().isEmpty())){canciones[fila].nombre   = ui->txtNombre->text().toStdString();}
    if (!(ui -> txtArtista -> text().isEmpty())){canciones[fila].artista   = ui->txtArtista->text().toStdString();}
    if (!(ui -> txtGenero -> text().isEmpty())){canciones[fila].genero   = ui->txtGenero->text().toStdString();}
    if (!(ui -> txtDuracion -> text().isEmpty())){canciones[fila].duracion = ui->txtDuracion->text().toStdString();}


    guardarArchivo();
    mostrarTabla();
}
//---------------------------------------------------------------------------------------
//actulizar ids para que sean consecutivos
void actualizarIDs(vector <Cancion> &c){
    for (size_t i = 0; i < c.size(); i ++){
        c[i].id  = i + 1;
    }
}
//----------------------------------------------------


}
