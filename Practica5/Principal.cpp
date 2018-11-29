#include <iostream>
#include "FuncionesAuxiliares.hpp"
void Multiplicacion();

using namespace std;

int main(){
     
    int opcion;
    do{
      opcion=menu();
      
      switch(opcion){
         case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
 
         case 1: 
             AlgMochila(); 
            break;

         case 2:
            Cambio();
            break;        

         case 3:
            MochilaTiempo();
            break;

         case 4:
            CambioTiempo();
            break;

         default:
            std::cout<<"Opcion incorrecta"<<std::endl;
         
      }
    }while(opcion!=0);

}




