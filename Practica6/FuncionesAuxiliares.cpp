#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include "NReinas.hpp"
#include "Tiempo.hpp"
#include "MinimosCuadrados.hpp"
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



void solucionNReinasLasVegas(){
  srand(time(NULL));
   std::cout<<"Introduce la cantidad de reinas: ";
   int n;
   std::cin>>n;
   if(n<3){
     std::cout<<"Error, numero de reinas invalido"<<std::endl;
     return;
   }
  NReinas prueba;
  bool x=LasVegasNreinas(prueba,n);
  while(!x){
    x=LasVegasNreinas(prueba,n);
  }
  std::cout<<prueba<<std::endl; 
  std::cin.ignore();
}


void analisisBacktracking(){
 Clock tim;

 std::cout<<"Introduce el limite inferior: ";
   int n;
   std::cin>>n;
   if(n<3){
     std::cout<<"Error, numero de reinas invalido"<<std::endl;
     return;
   }

 std::cout<<"Introduce el limite inferior: ";
   int lim;
   std::cin>>lim;
   if(lim<3||lim<n){
     std::cout<<"Error, numero de reinas invalido"<<std::endl;
     return;
   }

  std::cout<<"Introduce las repeticiones"<<std::endl;
  int rep;
  std::cin>>rep;
  if(rep<1){std::cout<<"Error"<<std::endl; return;}
  
  std::vector <double> muestraReal;
  std::vector <double> muestra;
  std::vector <double> tiempo;
  double tiempo_pasado;
  double tam_medio;
  for(int i=n;i<=lim;i++){
      tiempo_pasado=0;
      muestra.push_back(i);
      muestraReal.push_back(factorial(i));
   for(int k=0;k<rep;k++){
      std::vector<NReinas> solucionNreinas;
      tim.start();
       BacktrackingNreinas(solucionNreinas,n);
      if (tim.isStarted()){
          tim.stop();
          tiempo_pasado+=tim.elapsed();
         }
    }
    tiempo.push_back(tiempo_pasado/rep);
   } 

  std::vector<double> tiempo_estimado(muestra.size());
  std::vector<std::vector<double> > sol=calcularMinimosCuadrados(muestraReal, tiempo,2);
  std::ofstream file;
  file.open("NReinasBacktracking.txt");
  for(int i=0;i<muestra.size();i++){
     tiempo_estimado[i]=calcularValorAprox(muestraReal[i],sol,2);       
     file<<muestra[i]<<" "<<tiempo[i]<<" "<<tiempo_estimado[i]<<std::endl;}
     
  file.close();
  system("../graficaMochila.sh");
  std::cout<<"\nFunción de minimos cuadrados: "<<sol[1][0]<<"X+"<<sol[0][0]<<std::endl;
  std::cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo)<<std::endl; 

 double valor=1;
 while(valor!=0){
    std::cout<<"\nIntroduce valor para estimar(n=0,salir):";
    std::cin>>valor;
    if(valor>0){
    std::cout<<"La estimacion del tiempo para ese valor es de ";
    TiempoAlgoritmos(calcularValorAprox(valor,sol,2));}
   }
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
      }////////////////////////////////////////////////////////// 5 3 8 4 7 1 6 2
     else k--;
   }
}

bool LasVegasNreinas(NReinas &solucion,int n){
  NReinas aux(n);
  std::vector <int> ok;
  int contador;
  for(int i=0;i<n;i++){
     contador=0;
     for(int j=0;j<n;j++){
        aux.setReina(i,j+1);
        if(aux.lugar(i)){
           contador++; ok.push_back(j+1);
        }
     } 
     if(contador==0) return false;
     aux.setReina(i,ok[rand()%ok.size()]);
     ok.clear();
  }
  if(contador==0) return false;  
  solucion=aux;
  return true;
}

double factorial(double i){
  double x=1;
  for(int j=1;j<=i;j++){
    x=x*j;
  }
  return x;
}
