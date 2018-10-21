#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include <iostream>
#include "Tiempo.hpp"
#include <cmath>
#include <stack>
#include <vector>
#include <fstream>
#include "MinimosCuadrados.hpp"
#include <cstdlib>

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
	std::cout <<  "[1] Calcular numeros combinatorios recursivos sin lista";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Calcular numeros combinatorios recursivos con lista";

	posicion++;

	PLACE(posicion++,10);
	std::cout << "[3] Calcular numeros combinatorios iterativos";

	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Volver al menu principal";
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
      switch(opcion){
         case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
 
         case 1: 
            numerosCombinatoriosRecursivosSinTabla(); 
            break;

         case 2:
            numerosCombinatoriosRecursivosConTabla();
            break;        
 
         case 3:
            numerosCombinatoriosIterativos();
            break;

         default:
            std::cout<<"Opcion incorrecta"<<std::endl;
         
      }
	
}




void numerosCombinatoriosRecursivosSinTabla(){ 

  Clock time;
  int n,rep;
  
  std::cout<<"Introduce el valor de n:";

  std::cin>>n;
  if(n<1) return;
   std::cout<<"Introduce el numero de repeticiones:";

  std::cin>>rep;
  if(rep<1) return;

  std::vector<double> tiempo_recursivo_sin_lista;
  tiempo_recursivo_sin_lista.resize(n,0);

  std::vector<double> muestra_recursivo_sin_lista;
  muestra_recursivo_sin_lista.resize(n,0);
  double tiempoPasado=0;
 
   for(int i=1;i<=n;i++){ 
     muestra_recursivo_sin_lista[i-1]=i;
     tiempoPasado=0;
     for(int r=0;r<rep;r++){
        time.start();
        for(int j=0;j<=i;j++){    

           combinatorioRecursivo(i,j);}
         if (time.isStarted()){
          time.stop();
          tiempoPasado+=time.elapsed();
         }
       
       }
     tiempo_recursivo_sin_lista[i-1]=tiempoPasado/rep;
    
    }
  std::vector<double> muestra_recursivo_sin_lista2(n,0);
  std::vector<double> tiempo_estimado(n,0);
   for(int i=0;i<n;i++) muestra_recursivo_sin_lista2[i]=pow(2,muestra_recursivo_sin_lista[i]);
  std::vector<std::vector<double> > sol=calcularMinimosCuadrados(muestra_recursivo_sin_lista2, tiempo_recursivo_sin_lista,2);
  std::ofstream file;
  file.open("combinatorioRecursivoSinTabla.txt");
  for(int i=0;i<n;i++){ 
     tiempo_estimado[i]=sol[0][0]+(sol[1][0]*pow(2,muestra_recursivo_sin_lista[i]));
     file<<muestra_recursivo_sin_lista[i]<<" "<<tiempo_recursivo_sin_lista[i]<<" "<<tiempo_estimado[i]<<std::endl;
     }
  file.close();
  std::cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo_recursivo_sin_lista)<<std::endl;
  std::cin.ignore();
  system("../graficaRecursivaSinTabla.sh");

  double valor=1;
  while(valor!=0){
    std::cout<<"\nIntroduce valor para estimar(n=0,salir):";
    std::cin>>valor;
    long double anyos=(sol[0][0]+(sol[1][0]*pow(2,valor)))/(3,1536*pow(10,13));
    std::cout<<"La estimacion del tiempo para ese valor es "<<anyos<<" en años"<<std::endl;
   }


}



long double combinatorioRecursivo(long double n, long double k){
      if((k==0)||(k==n)) return 1;
      else
        return combinatorioRecursivo(n-1,k-1)+combinatorioRecursivo(n-1,k);
 }




void numerosCombinatoriosRecursivosConTabla(){
  Clock time;
  int n,rep;
  
  std::cout<<"Introduce el valor de n:";

  std::cin>>n;
  if(n<1) return;

   std::cout<<"Introduce el numero de repeticiones:";

  std::cin>>rep;
  if(rep<1) return;

  std::vector<double> tiempo;
  tiempo.resize(n,0);

  std::vector<double> muestra;

  muestra.resize(n,0);
  double tiempoPasado=0;
 
   for(int i=1;i<=n;i++){ 
     muestra[i-1]=i;
     tiempoPasado=0;
     for(int r=0;r<rep;r++){
        std::vector<std::vector<long double> > tabla(i+1, std::vector<long double>(i+1,0));
        time.start();
        for(int j=0;j<=i;j++){    

           combinatorioRecursivoConTabla(i,j,tabla);}
         if (time.isStarted()){
          time.stop();
          tiempoPasado+=time.elapsed();
         }
       
       }
     tiempo[i-1]=tiempoPasado/rep;
    
    }
  std::vector<double> tiempo_estimado(n,0);
  std::vector<std::vector<double> > sol=calcularMinimosCuadrados(muestra, tiempo,3);
  std::ofstream file;
  file.open("combinatorioRecursivoConTabla.txt");
  for(int i=0;i<n;i++){ 
     tiempo_estimado[i]=calcularValorAprox(muestra[i],sol,3);
     file<<muestra[i]<<" "<<tiempo[i]<<" "<<tiempo_estimado[i]<<std::endl;
     }
  file.close();
  std::cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo)<<std::endl;
  system("../graficaRecursivaConTabla.sh");

  double valor=1;
  while(valor!=0){
    std::cout<<"\nIntroduce valor para estimar(n=0,salir):";
    std::cin>>valor;
    std::cout<<"La estimacion del tiempo para ese valor es "<<calcularValorAprox(valor,sol,3)<<" en mcs"<<std::endl;
   }

}


long double combinatorioRecursivoConTabla(long double n, long double k,std::vector < std::vector< long double> > &tabla){
      if((k==0)||(k==n)) return 1;
      else{
        if(tabla[n][k]!=0) return tabla[n][k];
        else{ long double comb=combinatorioRecursivoConTabla(n-1,k-1,tabla)+combinatorioRecursivoConTabla(n-1,k,tabla);
              tabla[n][k]=comb; 
              return comb;
            }
      }
 }


void numerosCombinatoriosIterativos(){
  Clock time;
  int n,rep;
  
  std::cout<<"Introduce el valor de n:";

  std::cin>>n;
  if(n<1) return;
  
 std::cout<<"Introduce el numero de repeticiones:";

  std::cin>>rep;
  if(rep<1) return;

  std::vector<double> tiempo;
  tiempo.resize(n,0);

  std::vector<double> muestra;
  muestra.resize(n,0);
  double tiempoPasado=0;
 
   for(int i=1;i<=n;i++){ 
     muestra[i-1]=i;
     tiempoPasado=0;
       for(int r=0;r<rep;r++){
        for(int j=1;j<=i;j++){
            time.start();

           combinatorioIterativo(i,j);
         if (time.isStarted()){
          time.stop();
          tiempoPasado+=time.elapsed();
         }
       }
       }
     tiempo[i-1]=tiempoPasado/rep;
    
    }
  std::vector<double> tiempo_estimado(n);
  std::vector<std::vector<double> > sol=calcularMinimosCuadrados(muestra, tiempo,3);
  std::ofstream file;
  file.open("combinatorioIterativo.txt");
  for(int i=0;i<n;i++){
     tiempo_estimado[i]=calcularValorAprox(muestra[i],sol,3);       
     file<<muestra[i]<<" "<<tiempo[i]<<" "<<tiempo_estimado[i]<<std::endl;}
     
  file.close();
 
  system("../graficaIterativo.sh");
  std::cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo)<<std::endl; 

 double valor=1;
 while(valor!=0){
    std::cout<<"\nIntroduce valor para estimar(n=0,salir):";
    std::cin>>valor;
    std::cout<<"La estimacion del tiempo para ese valor es "<<calcularValorAprox(valor,sol,3)<<" en mcs"<<std::endl;
   }
}





long double combinatorioIterativo(long double n,long  double k){
   if((k==0)||(k==n)) return 1;
   long double solucion=n;
   
     for(int i=n-1;i>k;i--)
           solucion*=i;

   long double s=1;
     for(int i=2;i<=n-k;i++)
           s*=i;

   return  solucion/s;
}
    



void realizarHanoi(){
   Clock time;
  int n;
  
  std::cout<<"Introduce el valor de n(mayor que 3):";

  std::cin>>n;
  if(n<3) return;
    for(int i=3;i<=n;i++){
       int movimientos=0;
       std::vector<std::stack <int> > varillas(3);
       for(int j=i;j>0;j--) varillas[0].push(j);
       time.start();
       hanoi(varillas,i,1,2,movimientos);
       if (time.isStarted()){
          time.stop();}
       std::cout<<movimientos<<std::endl; 
     }

}



void hanoi(std::vector<std::stack <int> > &varillas,int nDiscos,int i,int j,int &movimientos){ 
     if(nDiscos>0){
         hanoi(varillas,nDiscos-1,i,6-i-j,movimientos);  
         varillas[j].push(varillas[i].top());varillas[i].pop();movimientos++;
         hanoi(varillas,nDiscos-1,6-i-j,j,movimientos); 
     }
}
