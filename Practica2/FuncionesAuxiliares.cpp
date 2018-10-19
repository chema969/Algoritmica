#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include <iostream>
#include "Tiempo.hpp"
#include <vector>
#include <fstream>
#include "MinimosCuadrados.hpp"
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
	std::cout <<  "[1] Calcular numeros combinatorios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Torres de hanoi";

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



void numerosCombinatorios(){ 

  Clock time;
  int n;
  
  std::cout<<"Introduce el n para recursividad sin lista:";

  std::cin>>n;
  if(n<1) return;
  
  std::vector<double> tiempo_recursivo_sin_lista;
  tiempo_recursivo_sin_lista.resize(n,0);

  std::vector<double> muestra_recursivo_sin_lista;
  muestra_recursivo_sin_lista.resize(n,0);
  double tiempoPasado=0;
 
   for(int i=1;i<=n;i++){ 
     muestra_recursivo_sin_lista[i-1]=i;
     tiempoPasado=0;
        for(int j=1;j<=i;j++){
            time.start();

           combinatorioRecursivo(i,j);
         if (time.isStarted()){
          time.stop();
          tiempoPasado+=time.elapsed();
         }
       }
     tiempo_recursivo_sin_lista[i-1]=tiempoPasado;
    
    }
 
  std::vector<std::vector<double> > sol=calcularMinimosCuadrados(muestra_recursivo_sin_lista, tiempo_recursivo_sin_lista,3);
  std::ofstream file;
  file.open("combinatorioRecursivoSinLista.txt");
  for(int i=0;i<n;i++) 
     file<<muestra_recursivo_sin_lista[i]<<" "<<tiempo_recursivo_sin_lista[i]<<" "<<calcularValorAprox(muestra_recursivo_sin_lista[i],sol,3)<<std::endl;
  file.close();
  for (int i=0;i<muestra_recursivo_sin_lista.size();i++)std::cout<<muestra_recursivo_sin_lista[i]<<std::endl;

}



long unsigned int combinatorioRecursivo(long unsigned int n, long unsigned int k){
      if((k==0)||(k==n)) return 1;
      else
        return combinatorioRecursivo(n-1,k-1)+combinatorioRecursivo(n-1,k);
 }




long unsigned int combinatorioIterativo(long unsigned int n,long unsigned int k){
    
   long unsigned int solucion=n;
   
     for(int i=n-1;i>k;i--)
           solucion*=i;

   long unsigned int s=1;
     for(int i=2;i<=n-k;i++)
           s*=i;

   return  solucion/s;
}
    







void hanoi(){ }
