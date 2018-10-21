#include <iostream>
#include "FuncionesAuxiliares.hpp"



int main(){
     
    int opcion;
    do{
      opcion=menu();
      
      switch(opcion){
         case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
 
         case 1: 
            numerosCombinatorios(); 
            break;

         case 2:
            realizarHanoi();
            break;        

         default:
            std::cout<<"Opcion incorrecta"<<std::endl;
         
      }
    }while(opcion!=0);

}
