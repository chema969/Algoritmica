#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include "SistemaMonetario.hpp"
#include "Moneda.hpp"
#include <iostream>
#include <fstream>
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
	std::cout <<  "[1] Realizar el problema del viajante de comercio";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Realizar el problema del cambio";

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


void Mochila(){}
  
void Cambio(){
  SistemaMonetario sist;
  //std::cout<<"Introduce el fichero con los vertices:"<<std::endl;
   std::string nombre="../Euros.txt";
  //std::cin>>nombre;
   std::ifstream fichero;
     fichero.open(nombre.c_str());

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
         std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
         return;}
  fichero>>sist;//se meten los datos del fichero
  fichero.close();
  
  std::cout<<"Introduce el numero a cambiar"<<std::endl;
  int n;
  std::cin>>n;
  if(n<1){std::cout<<"Error"<<std::endl; return;}
  
  std::vector<std::vector <int> > monedasCamb;
  cambAlgDinam(sist,n,monedasCamb);
  std::vector<Moneda> sistema=sist.getSistemaMonetario();

 
  for(int i=0;i<monedasCamb.size();i++){
       for(int j=0;j<monedasCamb[i].size();j++){
         if(monedasCamb[i][j]!=-1)
          std::cout<<monedasCamb[i][j]<<" ";
         else
          std::cout<<"∞ ";
        }
        std::cout<<"\n";
  }
  std::vector <int> solucion(sist.size(),0);
  int i=monedasCamb.size()-1,j=n;
  while(j>0&&i>0){ 
     if(monedasCamb[i][j]==monedasCamb[i-1][j]) i--;
     else{
        if( monedasCamb[i][j]==1+monedasCamb[i][j-sistema[i].getValor()]){
             solucion[i]++;      j=j-sistema[i].getValor();
         }
       }
  }

 if(i<=0||j<0){
        std::cout<<"NO TIENE SOLUCION\n";
     }
 else{
  std::cout<<BIBLUE<<"El cambio requiere:"<<RESET<<std::endl;
  for(int k=0;k<solucion.size();k++){
     if(solucion[k]!=0)
         std::cout<<solucion[k]<<" "<<sistema[k].getTipo()<<" de "<<sistema[k].getValor()<<" centimos\n";
  }
  }
  std::cin.ignore();
  std::cin.ignore();
}





void cambAlgDinam(const SistemaMonetario &sist,int n, std::vector<std::vector <int> > &vectorCamb){
  std::vector<std::vector <int> > monedasCamb(sist.size(),std::vector<int>(n+1,0));
  std::vector<Moneda> sistema=sist.getSistemaMonetario();


  for(int i=0;i<monedasCamb.size();i++){
       for(int j=1;j<monedasCamb[i].size();j++){
          if((i==0)&&(j<sistema[i].getValor()))
                 monedasCamb[i][j]=-1;//Considero -1 como el valor infinito
          else{
               if(i==0){
                 if(monedasCamb[i][j-sistema[0].getValor()]==-1)  monedasCamb[i][j]=-1;
                 else monedasCamb[i][j]=1+monedasCamb[i][j-sistema[0].getValor()];  
                 }
               else{
                  if(j<sistema[i].getValor())
                      monedasCamb[i][j]=monedasCamb[i-1][j];
                  else{
                      if(monedasCamb[i][j-sistema[i].getValor()]==-1) monedasCamb[i][j]=monedasCamb[i-1][j];
                      else monedasCamb[i][j]=min(monedasCamb[i-1][j],1+monedasCamb[i][j-sistema[i].getValor()]);
                      }
                   }
               }   
       }
  }
  vectorCamb=monedasCamb;
}


int min(int i,int j){
    if(i==-1) return j;
    if(j==-1) return i;
    if(j>i) return i;
    else return j;
}

