#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include "SistemaMonetario.hpp"
#include "Moneda.hpp"
#include "Mochila.hpp"
#include "Material.hpp"
#include "MinimosCuadrados.hpp"
#include "Tiempo.hpp"
#include <iostream>
#include <vector>
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
	std::cout <<  "[1] Realizar el problema de la mochila";

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


void AlgMochila(){
   std::cout<<"Introduce la capacidad de la mochila"<<std::endl;
   int din;
   std::cin>>din;
   if(din<1){std::cout<<"Error"<<std::endl; return;}
   Mochila moc(din);
   std::vector<Material> m;
   
   std::string nombre="../Materiales.txt";
   std::ifstream fichero;
     fichero.open(nombre.c_str());

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
         std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
         return;}
  Material aux;
   
  while(fichero>>aux) m.push_back(aux);
           
  fichero.close();
  std::vector<std::vector <int> > matrizSol;
  mochAlgDin(m, matrizSol,din);
  getSolucionMochila(m, matrizSol,moc);
  std::cout<<moc<<"\n";
  std::cin.ignore();
}
  
void mochAlgDin(const std::vector<Material> &m,std::vector<std::vector <int> > &solucion,int n){
    std::vector<std::vector <int> > matrizSol(m.size(),vector<int>(n+1,0));
    for(int i=0;i<matrizSol.size();i++){
       for(int j=1;j<matrizSol[i].size();j++){
          if(j<m[i].getCantidad()&&i==0) matrizSol[i][j]=0;
          else{
              if(i==0)
                 matrizSol[i][j]=m[i].getCantidad()*m[i].getPrecio();
              else{
                if(j<m[i].getCantidad())
                   matrizSol[i][j]=matrizSol[i-1][j];
                else
                   matrizSol[i][j]=max(matrizSol[i-1][j],(int)(m[i].getCantidad()*m[i].getPrecio()+matrizSol[i-1][j-m[i].getCantidad()]));
                 }
             }
       }
    }
  solucion=matrizSol;
}

void getSolucionMochila(const std::vector<Material> &m,const std::vector<std::vector <int> > &solucion,Mochila &moc){
   int i=m.size()-1;
   int j=solucion[i].size()-1;
   while(j>0&&i>=0){ 
     if(i==0){
       if(m[0].getCantidad()<=moc.getCapacidadRestante())  moc.insertarMaterial(m[i]);
       i--;
    }
    else{
     if(solucion[i][j]==solucion[i-1][j]) i--;
     else{
            //std::cout<<i<<std::endl;
       if( solucion[i][j]==m[i].getCantidad()*m[i].getPrecio()+solucion[i-1][j-m[i].getCantidad()]){
             moc.insertarMaterial(m[i]);      j=j-m[i].getCantidad(); i--;}
       //  }
       }
     }
  }

}

int max(int i,int j){
   if(j>i) return j;
   else return i;
 }

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

 
 /* for(int i=0;i<monedasCamb.size();i++){
       for(int j=0;j<monedasCamb[i].size();j++){
         if(monedasCamb[i][j]!=-1)
          std::cout<<monedasCamb[i][j]<<" ";
         else
          std::cout<<"∞ ";
        }
        std::cout<<"\n";
  }*/
  std::vector <int> solucion(sist.size(),0);
  int i=monedasCamb.size()-1,j=n;
 
 if(monedasCamb[monedasCamb.size()
  while(j>0&&i>0){ 
     if(monedasCamb[i][j]==monedasCamb[i-1][j]) i--;
     else{
        if( monedasCamb[i][j]==1+monedasCamb[i][j-sistema[i].getValor()]){
             solucion[i]++;      j=j-sistema[i].getValor();
         }
       }
  }
 if(i==0&& monedasCamb[i][j]==1+monedasCamb[i][j-sistema[i].getValor()]){ solucion[0]++;}
 

  std::cout<<BIBLUE<<"El cambio requiere:"<<RESET<<std::endl;
  for(int k=0;k<solucion.size();k++){
     if(solucion[k]!=0)
         std::cout<<solucion[k]<<" "<<sistema[k].getTipo()<<" de "<<sistema[k].getValor()<<" centimos\n";
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

