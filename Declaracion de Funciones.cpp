//Integrantes:
//-Villa Proaño Roddik Estift
//-Estrada Velazco Anderson Jose
//-Sanchez Sanchez Joel Efrain
//Tema:
//Sistema CRUD de gestión y clasificación de música


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void mostrarRegistros(){
	
}

void editar

void menuPrincipal(int opcion){
	do{
		cout<<"===GESTION Y CLASIFICACION DE MUSICA==="<<endl;
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
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 0:
				cout<<"Saliendo..."<<endl;
				break;	
		}
	}while(opcion != 0);
}



int main(){
	int opc;
	
	menuPrincipal(opc);
	
	
	return 0;
}
