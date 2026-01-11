/*
Integrantes:
- Villa Proaño Roddik Estift
- Estrada Velazco Anderson Jose
- Sanchez Sanchez Joel Efrain

Tema:
Sistema CRUD de gestión y clasificación de música
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include <clocale> //TILDES

using namespace std;

struct cancion{
	string nombre, genero, artista;
	int id;
	string duracion;
};

//-------------------- INGRESAR ----------------------

void IngresarCancion(vector<cancion> &s){
	cancion song;
	ofstream archivo("music.txt", ios::app);
	
	
	cout<<" ---- REGISTRAR CANCION ---- \n";
	cout<<" Ingrese ID de la cancion: ";
	cin>>song.id;
	cin.ignore();
	cout<<" Ingrese el nombre de la canción: ";
	getline(cin,song.nombre);
	
	cout<<" Ingrese el artista: ";
	getline(cin,song.artista);
	
	cout<<" Ingrese el genero: ";
	getline(cin,song.genero);
	
	cout<<" Ingrese la duración (mm:ss): ";
	cin>>song.duracion;
	
	//GUARDO EN EL ARCHIVO
	archivo << song.id << ";"
	    	<< song.nombre << ";"
	        << song.artista << ";"
	        << song.genero << ";"
	        << song.duracion << endl;
	
	
	s.push_back(song);
	
	cout<<"- Canción Registrada con Éxito-"<<endl;
}

//------------- MOSTRAR ------------------------------
void mostrarRegistro(vector<cancion>& s){
	cout<<"\n-Registro de canciones-"<<endl;
	
	cout<<"-----------------------------------------------------";
	for(auto song : s){
		cout<<"\n ID: "<<song.id<<endl;
		cout<<" Nombre: "<<song.nombre<<endl;
		cout<<" Artista: "<<song.artista<<endl;
		cout<<" Género: "<<song.genero<<endl;
		cout<<" Duración (mm:ss): "<<song.duracion<<endl;
		cout<<"-----------------------------------------------------";
		
	}
	
	cout<<endl;
}

//----------EDITAR-------------------------------------------------------
void editarCancion(vector<cancion>& s) {
	int id;
	cout << " Ingrese el ID de la canción a editar...\n";
	cout << " ID: ";
	cin >> id;

	for (size_t i = 0; i < s.size(); i++) {
		if (s[i].id == id) {
			string nombreC, nombreA, Genero, duracion;
			int opcion;
			cout << " Ingresar que desea cambiar..\n" <<
				" 1.- Nombre de la canción\n" <<
				" 2.- Artista\n" <<
				" 3.- Genero\n" <<
				" 4.- Duración\n" <<
				" Ingresar una opción :";
			cin >> opcion;
			cin.ignore();
			cout << " Ingresar ...\n";
			switch (opcion){
			case 1:
				cout << " Nuevo Nombre de la canción: ";
				getline(cin, nombreC);
				s[i].nombre = nombreC;
				break;
			case 2:
				cout << " Nuevo Artista: ";
				getline(cin, nombreA);
				s[i].artista = nombreA;
				break;
			case 3:
				cout << " Genero de de la canción: ";
				getline(cin, Genero);
				s[i].genero = Genero;
				break;
			case 4:
				cout << " Duración (hh:mm): ";
				cin >> duracion;
				s[i].duracion = duracion;
				break;
			}
			break;
		}
	}
	cout<<endl;
	
}


//-------------- ELIMINAR CANCION------------------------------------------------------------
void eliminarCancion(vector<cancion>& s) {
	int id;
	cout <<" Ingrese el ID de la canción a eliminar...\n";
	cout <<" ID: ";
	cin >> id;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i].id == id) {
			cout << " Eliminando " << s[i].nombre << " de " << s[i].artista << endl;
			s.erase(s.begin() + i);
			cout << " Canción eliminada\n";
			break;
		}
	}
	cout<<endl;
	
}

//-------------- ELIMINAR GÉNERO------------------------------------------------------------

void eliminarGenero(vector<cancion>& s) {
    string generoEliminar;
    cout << "Ingrese el genero a eliminar: ";
    cin.ignore();
    getline(cin, generoEliminar);

    bool encontrado = false;

    for (size_t i = 0; i < s.size(); ) {
        if (s[i].genero == generoEliminar) {
            s.erase(s.begin() + i);
            encontrado = true;
        } else {
            i++;
        }
    }

    if (encontrado) {
        cout<< "Genero eliminado correctamente.\n";
    } else {
        cout<< "No se encontraron canciones con ese genero.\n";
    }
}





//----------------- MENU -------------------------------------------------------
void menuPrincipal(vector<cancion> &s){
	
	int opcion;
	do{
		cout<<"\n ===== GESTIÓN Y CLASIFICACIÓN DE MÚSICA ===== "<<endl;
		cout<<" 1.Ingresar una Canción: "<<endl;
		cout<<" 2.Mostrar Registro de Canciones"<<endl;
		cout<<" 3.Editar Registro de Canciones"<<endl;		
		cout<<" 4.Eliminar una Canción"<<endl;		
		cout<<" 5.Eliminar Género Musical"<<endl;		
		cout<<" 0.Salir"<<endl;	
		cout<<" Ingrese una opción: ";	
		cin>>opcion;
		cout<<endl;
	
		switch(opcion){
			case 1:
				IngresarCancion(s);
				break;
			case 2:
				mostrarRegistro(s);
				break;
			case 3:
				editarCancion(s);
				break;
			case 4:
				eliminarCancion(s);
				break;
			case 5:
				eliminarGenero(s);
				break;
			case 0:
				cout<<" Saliendo del Sistema...\n-Que tenga un Lindo Día-"<<endl;
				break;
			default: 
				cout<<" Opcion No válida. Intente nuevamente...\n";
		}
	}while(opcion != 0);
}



int main(){
	setlocale(LC_ALL, "");

	
	int opc;
	vector<cancion> canciones; 
	menuPrincipal(canciones);
	
	
	return 0;
}
