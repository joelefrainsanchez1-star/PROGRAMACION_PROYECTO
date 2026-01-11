//Integrantes:
//-Villa Proaño Roddik Estift
//-Estrada Velazco Anderson Jose
//-Sanchez Sanchez Joel Efrain
//Tema:
//Sistema CRUD de gestión y clasificación de música
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
struct cancion{
	string nombre,genero,artista;
	int id;
	double duracion;
};

void IngresarCancion(vector<cancion> &s){
	cancion song;
	ofstream archivo("music.txt", ios::app);
	
	cout<<"Ingrese ID de la cancion: ";
	cin>>song.id;
	cin.ignore();
	cout<<"Ingrese el nombre de la cancion: ";
	getline(cin,song.nombre);
	cout<<"Ingrese el artista: ";
	getline(cin,song.genero);
	cout<<"Ingrese el genero: ";
	getline(cin,song.artista);
	cout<<"Ingrese la duracion: ";
	cin>>song.duracion;
	
	s.push_back(song);
	
	cout<<"-Cancion Registrada con Exito-"<<endl;
}

void mostrarRegistro(vector<cancion> s){
	cout<<"\n-Registro de canciones-"<<endl;
	
	for(auto song : s){
		cout<<"\nID: "<<song.id<<endl;
		cout<<"Nombre: "<<song.nombre<<endl;
		cout<<"Artista: "<<song.artista<<endl;
		cout<<"Genero: "<<song.genero<<endl;
		cout<<"Duracion: "<<song.duracion<<endl;
	}
	
	
}
//void editar(){
//	
//}

void menuPrincipal(vector<cancion> &s){
	
	int opcion;
	do{
		cout<<"\n===GESTION Y CLASIFICACION DE MUSICA==="<<endl;
		cout<<"1.Ingresar una Cancion: "<<endl;
		cout<<"2.Mostrar Registro de Canciones"<<endl;
		cout<<"3.Editar Registro de Canciones"<<endl;		
		cout<<"4.Eliminar una Cancion"<<endl;		
		cout<<"5.Eliminar Genero Musical"<<endl;		
		cout<<"0.Salir"<<endl;	
		cout<<"Ingrese una opcion: "<<endl;	
		cin>>opcion;
		
		switch(opcion){
			case 1:
				IngresarCancion(s);
				break;
			case 2:
				mostrarRegistro(s);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 0:
				cout<<"Saliendo del Sistema...\n-Que tenga un Lindo Dia-"<<endl;
				break;	
		}
	}while(opcion != 0);
}



int main(){
	int opc;
	vector<cancion> canciones; 
	menuPrincipal(canciones);
	
	
	return 0;
}
