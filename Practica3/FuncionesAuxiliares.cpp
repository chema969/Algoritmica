#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include <iostream>
#include "Entero.hpp"
#include <string>
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
	std::cout <<  "[1] Calcular la suma de dos numeros";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Calcular la multiplicación de dos numeros";

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


void Multiplicacion(){
  string x,y;
  int l;
  cout<<"Introduce el valor de ambos numeros separados por espacios"<<endl;
  cin>>x>>y;
  cout<<"Introduce el numero máximo a partir del cual dos numeros pueden multiplicarse\n"<<BIRED<<"AVISO: a partir de cuatro no se garantiza la solucion\n"<<RESET;
  cin>>l;
  if(isInteger(x)&&isInteger(y)){
   if(l>0){
    Entero i(x,l);
    Entero j(y,l);
    Entero k=i*j;
    cout<<BICYAN<<"\nEl resultado es "<<RESET<<k<<endl;
    cin.ignore();
    cin.ignore();
    }
   else{cout<<"Error, limite de multiplicación directa invalido"<<endl; cin.ignore();    cin.ignore();}
   
  } 
  else{ cout<<"Error, no son enteros"<<endl;    cin.ignore();    cin.ignore();}
   
   

}


void Suma(){
  string x,y;
  cout<<"Introduce el valor de ambos numeros separados por espacios"<<endl;
  cin>>x>>y;
  if(isInteger(x)&&isInteger(y)){
    Entero i(x);
    Entero j(y);
    Entero k=i+j;
    cout<<"\nEl resultado es "<<k<<endl;
    cin.ignore();
    cin.ignore();
   
  } 
  else{ cout<<"Error, no son enteros"<<endl;    cin.ignore();    cin.ignore();}

}
