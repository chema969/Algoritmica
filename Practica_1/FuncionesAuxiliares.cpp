#include "FuncionesAuxiliares.hpp"
#include <iostream>
#include "macros.hpp"
#include "Tiempo.hpp"
#include "Vector.hpp"
#include <fstream>


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
      
   std::ofstream fichero;
   fichero.open("seleccion.txt");
   
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
       return;
      }
   
    while(inicio<=fin){
      double tiempo=0;
      v.resize(inicio);

      for(int i=0;i<repeticiones;i++){
         v.rellenarVector();
         time.start();
         v.seleccion();
         if (time.isStarted())
	{
          time.stop();
          tiempo+=time.elapsed();
         }
      }     
     double aux=tiempo/repeticiones;
     fichero<<inicio<<" "<<aux<<"\n";                 
     inicio=inicio+subida;
   }
fichero.close();
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
   fichero.open("heapsort.txt");
   
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
       return;
      }
   
    while(inicio<=fin){
      double tiempo=0;
      v.resize(inicio);

      for(int i=0;i<repeticiones;i++){
         v.rellenarVector();
         v.heapify();
         time.start();
         v.heapsort();
         if (time.isStarted())
	{
          time.stop();
          tiempo+=time.elapsed();
         }
      }     
     double aux=tiempo/repeticiones;
     fichero<<inicio<<" "<<aux<<"\n";                 
     inicio=inicio+subida;
   }
fichero.close();
}
