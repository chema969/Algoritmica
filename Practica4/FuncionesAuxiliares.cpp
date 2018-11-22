#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include "SistemaMonetario.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int menu(){

	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Realizar el problema de la mochila";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Realizar el problema del cambio";

	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}

void Mochila(){
}

void Cambio(){
  SistemaMonetario sist;
  //std::cout<<"Introduce el fichero con los vertices:"<<std::endl;
   std::string nombre="../Euros.txt";
  //std::cin>>nombre;
   std::ifstream fichero;
     fichero.open(nombre.c_str());

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
         std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
         return;}
  fichero>>sist;//se meten los datos del fichero
  fichero.close();
  std::vector< std::vector <int> > solucion;


  std::cout<<"Introduce el numero a cambiar"<<std::endl;
  int n;
  std::cin>>n;
  if(n<1){std::cout<<"Error"<<std::endl; return;}
  
  solucion.resize(n+1,std::vector<int>(sist.size(),0));
  for (int i=0;i<solucion.size();i++){
    for(int j=0;j<n+1;j++){
    
    }
  }
}
