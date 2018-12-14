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
            solucionNReinas();
            break;

         case 2:
            solucionNReinasLasVegas();
            break;        

         case 3:
            analisisBacktracking();
            break;

         case 4:
            break;

         default:
            std::cout<<"Opcion incorrecta"<<std::endl;
         
      }
    }while(opcion!=0);

}




