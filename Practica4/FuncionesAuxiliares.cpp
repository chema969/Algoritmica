#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include <iostream>
#include "Grafo.hpp"
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
	std::cout <<  "[1] Realizar el problema del viajante de comercio";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Realizar el problema de la mochila";

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


void ViajanteDeComercio(){
   Grafo grafo;
   std::cout<<"Introduce el fichero con los vertices:"<<std::endl;
   std::string nombre;
   std::cin>>nombre;
   std::ifstream fichero;
     fichero.open(nombre.c_str());

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
         std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
         return;}
 
     Vertice aux;
     while(fichero>>aux){
          if(!grafo.findVertice(aux.getNombre()))
             grafo.insertVertice(aux.getNombre());
    }
      fichero.close();

    std::cout<<"Introduce el fichero con los lados y el resto de datos:"<<std::endl;
    std::cin>>nombre;
    fichero.open(nombre.c_str());

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
         std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
         return;}

     int size;
     fichero>>size;

     if(size!=grafo.size()){
         std::cout<<BIRED<<"El tamaño debe ser el mismo"<<RESET<<std::endl;
         return;
        }

     int dir;
     fichero>>dir;
     grafo.setDirigido(dir>0);
     
     for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
        int lado;
        fichero >> lado;
        if(lado>0){
          if(!grafo.adjacent(i,j))
            grafo.insertLado(i,j,lado);
        }
       }
     }
   Grafo solucion(dir>0);
   Viajante(grafo,solucion);
}



void Viajante(Grafo &grafo,Grafo &solucion){
    grafo.sortLados();
    grafo.gotoFirstVertice();
    do{
     solucion.insertVertice(grafo.currentVertice());
    }while( grafo.gotoNextVertice());
    int l=0;
    std::vector< Grafo > conjuntos(grafo.size());
    
    grafo.gotoFirstVertice();
    for(int i=0;i<grafo.size();i++){
       conjuntos[i].insertVertice(grafo.currentVertice());
        grafo.gotoNextVertice();
   }
    do{
     



    }while(l<grafo.size()-1);
}


Grafo unirConjuntos(const Grafo &a,const Grafo &b,int i,int j){
    




}
void Mochila(){


}
