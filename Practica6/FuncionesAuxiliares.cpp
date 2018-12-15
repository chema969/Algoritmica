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
   if(n<=3){
     std::cout<<"Error, numero de reinas invalido"<<std::endl;
     return;
   }
   std::vector<NReinas> soluciones;
  BacktrackingNreinas(soluciones,n);
  for(int i=0;i<soluciones.size();i++){
    std::cout<<soluciones[i]<<std::endl;
   }
  std::cin.ignore();
  std::cin.ignore();
}



void solucionNReinasLasVegas(){
  srand(time(NULL));
   std::cout<<"Introduce la cantidad de reinas: ";
   int n;
   std::cin>>n;
   if(n<=3){
     std::cout<<"Error, numero de reinas invalido"<<std::endl;
     return;
   }
  NReinas prueba;
  int NPruebas=1;
  bool x=LasVegasNreinas(prueba,n);
  while(!x){
    x=LasVegasNreinas(prueba,n);
    NPruebas++;
  }
  std::cout<<prueba<<std::endl; 
  std::cout<<"Solucion sacada tras "<<NPruebas<<" pruebas\n";
  std::cin.ignore();
  std::cin.ignore();
}


void analisisBacktracking(){
 Clock tim;

 std::cout<<"Introduce el limite inferior: ";
   int n;
   std::cin>>n;
   if(n<=3){
     std::cout<<"Error, numero de reinas invalido"<<std::endl;
     return;
   }

 std::cout<<"Introduce el limite superior: ";
   int lim;
   std::cin>>lim;
   if(lim<=3||lim<n){
     std::cout<<"Error, numero de reinas invalido"<<std::endl;
     return;
   }

  std::cout<<"Introduce las repeticiones: ";
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
      BacktrackingNreinas(solucionNreinas,i);
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
  system("../graficaBacktracking.sh");
  std::cout<<"\nFunción de minimos cuadrados: "<<sol[1][0]<<"X+"<<sol[0][0]<<std::endl;
  std::cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo)<<std::endl; 

 double valor=1;
 while(valor!=0){
    std::cout<<"\nIntroduce valor para estimar(n=0,salir):";
    std::cin>>valor;
    if(valor>0){
    std::cout<<"La estimacion del tiempo para ese valor es de ";
    TiempoAlgoritmos(calcularValorAprox(factorial(valor),sol,2));}
   }
}

void analisisNReinasLasVegas(){
   srand(time(NULL));
   int n=8;
 
   NReinas prueba;
   std::cout<<"Introduce el numero de pruebas: ";
   int rep;
   std::cin>>rep;
   double correctas=0,falsas=0;
   for(int x=0;x<rep;x++){
      if(LasVegasNreinas(prueba,n)){
            correctas++;
      } 
      else falsas++; 
   }
  std::cout<<BICYAN<<"El porcentaje de resultados correctos frente a incorrectos es de "<<RESET<<(correctas/rep)*100<<BICYAN<<"%"<<RESET<<std::endl; 
  std::cout<<BIBLUE<<"El algoritmo saca "<<RESET<<falsas/correctas<<BIBLUE<<" soluciones incorrectas por cada solucion correcta"<<RESET<<std::endl;
  std::cin.ignore();
  std::cin.ignore();
}

void comparacionNReinas(){
   srand(time(NULL));
    Clock tim;
    std::vector<double> muestra;
    std::vector<double> tiempoBacktrack;
    std::vector<double> tiempoLasVegas;
    std::cout<<"REALIZANDO PRUEBAS DESDE 8 HASTA 30 REINAS"<<std::endl;
    for(int i=8;i<=30;i++){
      muestra.push_back(i);
      std::vector<NReinas> solucionNreinas;
      NReinas p;
      tim.start();
      BacktrackingNreinas(solucionNreinas,i,true);
      if (tim.isStarted()){
          tim.stop();
         tiempoBacktrack.push_back( tim.elapsed());
      }
      tim.start();
      bool x=LasVegasNreinas(p,i);
      while(!x){
        x=LasVegasNreinas(p,i);
      }
      if (tim.isStarted()){
          tim.stop();
         tiempoLasVegas.push_back( tim.elapsed());
      }
    }    
    long double totalB=0,totalLV=0;
    for(int i=0;i<tiempoBacktrack.size();i++){
       std::cout<<muestra[i]<<" reinas: backtracking "<<tiempoBacktrack[i]<<"mcs, las vegas "<<tiempoLasVegas[i]<<"mcs"<<std::endl;
       totalB+=tiempoBacktrack[i]; totalLV+=tiempoLasVegas[i];
    }
    std::cout<<BIBLUE<<"TOTAL BACKTRACKING: "<<RESET;
    TiempoAlgoritmos(totalB);
    std::cout<<std::endl;
    std::cout<<BIBLUE<<"TOTAL LAS VEGAS: "<<RESET;
    TiempoAlgoritmos(totalLV);
    std::cout<<std::endl;
    std::cin.ignore();
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

long double factorial(double i){
  long double x=1;
  for(int j=1;j<=i;j++){
    x=x*j;
  }
  return x;
}
