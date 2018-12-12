#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include "NReinas.hpp"
#include "Tiempo.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
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
	std::cout <<  "[1] Realizar las n reinas por backtracking";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Realizar las n reinas por el algoritmo de las vegas";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[3] Analisis temporal de las n reinas con backtracking";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[4] Analisis del numero medio de puebas para obtener una solucion valida en Las Vegas";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[5] Comparación temporal entre backtracking y las vegas";
	//////////////////////////////////////////////////////////////////////////////
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



void solucionNReinas(){
   std::cout<<"Introduce la cantidad de reinas: ";
   int n;
   std::cin>>n;
   if(n<3){
     std::cout<<"Error, numero de reinas invalido"<<std::endl;
     return;
   }
   std::vector<NReinas> soluciones;
  BacktrackingNreinas(soluciones,n);
  for(int i=0;i<soluciones.size();i++){
    std::cout<<soluciones[i]<<std::endl;
   }
  std::cin.ignore();
}


void BacktrackingNreinas(std::vector<NReinas> &soluciones,int n,bool unaSol){
   soluciones.clear();
   NReinas aux(n);
   int k=0;

   while(k>=0){
     aux.setReina(k,aux.getValor(k)+1);
     while(aux.getValor(k)<=n && !aux.lugar(k)){
          aux.setReina(k,aux.getValor(k)+1);
          }
     if(aux.getValor(k)<=n){
        if(k==n-1){
           soluciones.push_back(aux);
            if(unaSol&&soluciones.size()) return; 
           }
        else{
           k++;
           aux.setReina(k,0);
        }
      }
     else k--;
   }
}

bool LasVegasNreinas(NReinas &solucion,int n){
  NReinas aux;
  int contador;
  for(int i=0;i<n;i++){
     contador=0;
     for(int j=0;j<n;j++){
        aux.setReina(i,j);
        if(aux.lugar(i)){
           contador++; 
        }
     } 
     if(contador==0) return false;
  }
  if(contador==0) return false;  
  solucion=aux;
  return true;
}


