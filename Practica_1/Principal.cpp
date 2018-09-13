#include "FuncionesAuxiliares.hpp"
#include <iostream>


int main(){
     
    int opcion;
    do{
      opcion=menu();
      
      switch(opcion){
         case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
 
         case 1: 
            metodoSeleccion(); 
            break;

         case 2:
            metodoMonticulos();
            break;        

         default:
            std::cout<<"Opcion incorrecta"<<std::endl;
         
      }
    }while(opcion!=0);

}
