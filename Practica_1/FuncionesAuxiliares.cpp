#include "FuncionesAuxiliares.hpp"
#include <vector>
#include <iostream>
#include "macros.hpp"
#include "Tiempo.hpp"
#include "Vector.hpp"
#include <fstream>
#include <cmath>
#include <cassert>
#include "sistemaEcuaciones.hpp"

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
	std::cout <<  "[1] Ordenación por selección";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Ordenación por montículos";

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







void metodoSeleccion(){
   Vector v;
   Clock time;
   int inicio,fin,subida,repeticiones;
   std::vector< std::vector< double> > minimosCuadrados;
   minimosCuadrados.resize(3);
   for(int i=0;i<3;i++)     minimosCuadrados[i].resize(3,0);  
   
   std::ofstream fichero;
   fichero.open("Seleccion.txt");
   
   std::cout<<"Introduce cantidad de datos inicial:";
   std::cin>>inicio;
   
   std::cout<<"Introduce cantidad de datos final:";
   std::cin>>fin;

   std::cout<<"Introduce aumento por repeticion:";  
   std::cin>>subida;
   
   std::cout<<"Introduce numero de repeticiones por cantidad:";
   std::cin>>repeticiones;

   if(!evaluarDatos(inicio,fin,subida,repeticiones)){
       std::cout<<"Datos erroneos, se vuelve al menu"<<std::endl;
       std::cin.ignore();
       return;
      }
   
  std::vector<double> tiempo(((fin-inicio)/subida)+1);
  std::vector<double> tamanyo(((fin-inicio)/subida)+1);
  int i=0;

    while(inicio<=fin){
      double tiempoPasado=0;
      v.resize(inicio);
      tamanyo[i]=inicio;

      for(int j=0;j<repeticiones;j++){
         v.rellenarVector();
         time.start();
         v.seleccion();
         if (time.isStarted())
	{
          time.stop();
          tiempoPasado+=time.elapsed();
         }
      }     
     tiempo[i]=tiempoPasado/repeticiones;
     inicio+=subida;
     i++;
  
   }

  std::vector< std::vector< double> > matrizDeCoeficientes= calcularMinimosCuadrados(tamanyo,3);
  std::vector< std::vector< double> > matrizDeTerminosIndependientes= calcularMinimosCuadradosTerminosInd(tamanyo,tiempo,3);
  

  std::vector< std::vector< double> > soluciones;
  soluciones.resize(3);
   for(int i=0;i<3;i++)     soluciones[i].resize(1,0);

  resolverSistemaEcuaciones(matrizDeCoeficientes, matrizDeTerminosIndependientes, 3, soluciones);
  
  std::vector<double> aprox;
  aprox.resize(tiempo.size(),0);
  for(unsigned int k=0;k<aprox.size();k++){
      for(double j=0;j<soluciones.size();j++){
         aprox[k]+=soluciones[j][0]*pow(tamanyo[k],j);
      }
  }

  std::cout<<"\nFunción de minimos cuadrados: "<<soluciones[2][0]<<"X^2+"<<soluciones[1][0]<<"X+"<<soluciones[0][0]<<std::endl;
  std::cout<<"\nEl coeficiente de determinacion es "<<determinacion(tiempo,aprox)<<std::endl;
  std::cin.ignore();
  std::cin.ignore();

  //Ahora imprimo el resultado final
  for(unsigned int i=0;i<tamanyo.size();i++){
      fichero<<tamanyo[i]<<" "<<tiempo[i]<<" "<<aprox[i]<<"\n";
   }
  fichero.close();
}
  








std::vector< std::vector< double> > calcularMinimosCuadradosTerminosInd(std::vector<double> tamanyo,std::vector<double>tiempo,int n){
   std::vector< std::vector< double> > minimosCuadradosTerminosInd;

   minimosCuadradosTerminosInd.resize(n);
   for(int i=0;i<n;i++) minimosCuadradosTerminosInd[i].resize(1,0);
   
   for(int i=0;i<n;i++)
         minimosCuadradosTerminosInd[i][0]=sumatorioMultValores(tamanyo,tiempo,i);

   return minimosCuadradosTerminosInd;
}









double sumatorioMultValores(std::vector<double> tamanyo,std::vector<double> tiempo,double n){
    assert(tiempo.size()==tamanyo.size());
    double aux=0;
   
    for(unsigned int i=0;i<tiempo.size();i++)
        aux+=(tiempo[i]*pow(tamanyo[i],n));


    return aux;


}


double media(std::vector<double> v){
   double media=0;
   for(unsigned int i=0;i<v.size();i++){
     media+=v[i];
   }
   return media/v.size();
}





double desviacionTipica(std::vector<double> v){
    double medias=media(v);
    double aux=0;
    for(unsigned int i=0;i<v.size();i++)
        aux+=pow(v[i]-medias,2); 
    aux=aux/v.size();
    aux=sqrt(aux);
    return aux;
   }

double varianza(std::vector<double> v){
    double medias=media(v);
    double aux=0;
    for(unsigned int i=0;i<v.size();i++)
        aux+=pow(v[i]-medias,2); 
    aux=aux/v.size();
    return aux;
   }


double covarianza(std::vector<double> v1,std::vector<double> v2){
    double mediaV1=media(v1);
    double mediaV2=media(v2);
    double sumV1V2=sumatorioMultValores(v1,v2,1);

    double covarianzas=sumV1V2/v1.size();
    covarianzas=covarianzas-mediaV1*mediaV2;
    return covarianzas;
}




double determinacion(std::vector<double> aprox,std::vector<double> tiempo){
     
    double varianzaAprox=varianza(aprox);
    double varianzaTiempo=varianza(tiempo);

    return (varianzaAprox/varianzaTiempo);
}









std::vector < std::vector< double> > calcularMinimosCuadrados(std::vector<double> tamanyo,int n){
   std::vector< std::vector< double> > minimosCuadrados;
   minimosCuadrados.resize(n);
   for(int i=0;i<n;i++)     minimosCuadrados[i].resize(n,0);  
   

   for(double i=0;i<n;i++){
      for(double j=0;j<n;j++){
          minimosCuadrados[i][j]=minimosCuadrados[j][i]=sumaVector(tamanyo,j+i);        
      }
   }


   return minimosCuadrados;
}










double sumaVector(std::vector<double> vector,double exponente){
     double aux=0;
      for(unsigned int i=0;i<vector.size();i++) aux+=pow(vector[i],exponente);
     return aux;
}









bool evaluarDatos(int inicio,int fin,int subida,int repeticiones){
  if(inicio<=0){ 
          std::cout<<"Datos de inicio no permitido"<<std::endl;
          return false;
         }

  if(fin<=0){
          std::cout<<"Datos de final no permitido"<<std::endl;
          return false;
         }

  if(subida<=0){ 
          std::cout<<"Datos de aumento no permitido"<<std::endl;
          return false;
         }

  if(repeticiones<=0){
          std::cout<<"Datos de repeticiones no permitido"<<std::endl;
          return false;
         }

  if(inicio>=fin){
          std::cout<<"Datos de inicio es mayor que de fin"<<std::endl;
          return false;
         }
  return true;
}




void metodoMonticulos(){ 
  Vector v;
   Clock time;
   int inicio,fin,subida,repeticiones;
      
   std::ofstream fichero;
   fichero.open("Heapsort.txt");
   
   std::cout<<"Introduce cantidad de datos inicial:";
   std::cin>>inicio;
   
   std::cout<<"Introduce cantidad de datos final:";
   std::cin>>fin;

   std::cout<<"Introduce aumento por repeticion:";  
   std::cin>>subida;
   
   std::cout<<"Introduce numero de repeticiones por cantidad:";
   std::cin>>repeticiones;

   if(!evaluarDatos(inicio,fin,subida,repeticiones)){
       std::cout<<"Datos erroneos, se vuelve al menu"<<std::endl;
       std::cin.ignore();
       return;
      }
   
   std::vector<double> tiempo(((fin-inicio)/subida)+1);
   std::vector<double> tamanyo(((fin-inicio)/subida)+1);
   int i=0;

    while(inicio<=fin){
      double tiempoPasado=0;
      v.resize(inicio);
      tamanyo[i]=inicio;

      for(int j=0;j<repeticiones;j++){
         v.rellenarVector();
         v.heapify();
         time.start();
         v.heapsort();
         if (time.isStarted())
	{
          time.stop();
          tiempoPasado+=time.elapsed();
         }
      }     
     tiempo[i]=tiempoPasado/repeticiones;             
     inicio=inicio+subida;
     i++;
   }
  std::vector<double> tamanyoLog=tamanyo;
  
  for(unsigned int i=0;i<tamanyoLog.size();i++)
            tamanyoLog[i]=z(tamanyoLog[i]);
 
  std::vector< std::vector< double> > matrizDeCoeficientes= calcularMinimosCuadrados(tamanyoLog,2);
  std::vector< std::vector< double> > matrizDeTerminosIndependientes= calcularMinimosCuadradosTerminosInd(tamanyoLog,tiempo,2);
  

  std::vector< std::vector< double> > soluciones;
  soluciones.resize(2);
   for(int i=0;i<2;i++)     soluciones[i].resize(1,0);

  resolverSistemaEcuaciones(matrizDeCoeficientes, matrizDeTerminosIndependientes, 2, soluciones);


  std::vector<double> aprox;
  aprox.resize(tiempo.size(),0);
  for(unsigned int k=0;k<aprox.size();k++){
         aprox[k]+=soluciones[0][0];
         aprox[k]+=soluciones[1][0]*z(tamanyo[i]);
  }

  std::cout<<"\nFunción de minimos cuadrados: "<<soluciones[1][0]<<"XlogX+"<<soluciones[0][0]<<std::endl;
  std::cout<<"\nEl coeficiente de determinacion es "<<determinacion(tiempo,aprox)<<std::endl;
  std::cin.ignore();
  std::cin.ignore();
  //Ahora imprimo el resultado final
  for(unsigned int i=0;i<tamanyo.size();i++){
      
      fichero<<tamanyo[i]<<" "<<tiempo[i]<<" "<<aprox[i]<<"\n";
   }

fichero.close();
}



double z(double n){return n*log10(n);}
