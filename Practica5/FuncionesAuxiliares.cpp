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
#include <ctime>
#include <cmath>
#include <cstdlib>
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
	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[3] Analisis temporal del problema de la mochila";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[4] Analisis temporal del problema del cambio";

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

void MochilaTiempo(){
  Clock tim;
  srand (time(NULL));

  std::cout<<"Introduce las repeticiones"<<std::endl;
  int rep;
  std::cin>>rep;
  if(rep<1){std::cout<<"Error"<<std::endl; return;}

  Mochila moc;
  std::vector<Material> m;
  std::vector<std::vector <int> > matrizSol;
  
  std::vector <double> muestraReal;
  std::vector <double> muestra;
  std::vector <double> tiempo;
  double tiempo_pasado;
  double tam_medio;
  for(int i=100;i<=200;i++){
      tam_medio=0;
      tiempo_pasado=0;
      muestra.push_back(i);
   for(int k=0;k<rep;k++){
      int tam;
      generarAleatoriamente(m,i,tam);
      moc.setCapacidad(tam);
      tam_medio+=tam;
      tim.start();
      mochAlgDin(m, matrizSol,moc.getCapacidad());
      getSolucionMochila(m, matrizSol,moc);
      if (tim.isStarted()){
          tim.stop();
          tiempo_pasado+=tim.elapsed();
         }
    }
    muestraReal.push_back(sqrt((tam_medio/rep)*i));
    tiempo.push_back(tiempo_pasado/rep);
   } 

  std::vector<double> tiempo_estimado(muestra.size());
  std::vector<std::vector<double> > sol=calcularMinimosCuadrados(muestraReal, tiempo,3);
  std::ofstream file;
  file.open("FicheroMochila.txt");
  for(int i=0;i<muestra.size();i++){
     tiempo_estimado[i]=calcularValorAprox(muestraReal[i],sol,3);       
     file<<muestra[i]<<" "<<tiempo[i]<<" "<<tiempo_estimado[i]<<std::endl;}
     
  file.close();
  system("../graficaMochila.sh");
  std::cout<<"\nFunción de minimos cuadrados: "<<sol[2][0]<<"X²+"<<sol[1][0]<<"X+"<<sol[0][0]<<std::endl;
  std::cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo)<<std::endl; 

 double valorn=1,valorN=1;
 while(valorn!=0&&valorN!=0){
    std::cout<<"\nIntroduce la cantidad de materiales y la capacidad de la mochila separados por espacios para estimar(0 0,salir):";
    std::cin>>valorn>>valorN;
    if(valorn>0&&valorN>0){
    std::cout<<BIBLUE<<"La estimacion del tiempo para ese valor es de "<<RESET;
    TiempoAlgoritmos(calcularValorAprox(sqrt(valorn*valorN),sol,3));}
   }
}

void generarAleatoriamente(std::vector<Material> &mat,int i,int &tamMochila){
   std::vector<Material> m;
   int cantidad_total=0;
   for(int j=0;j<i;j++){
      int k=rand()%100+1;
      cantidad_total+=k;
      Material aux(j,k,rand()%100+1);
      m.push_back(aux);
   }
  mat=m;
  tamMochila=cantidad_total/2;
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
  std::cout<<BIBLUE<<"EL coste total de la mochila es "<<RESET<<matrizSol[matrizSol.size()-1][matrizSol[0].size()-1]<<std::endl;
  std::cin.ignore();
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
            
       if( solucion[i][j]==m[i].getCantidad()*m[i].getPrecio()+solucion[i-1][j-m[i].getCantidad()]){
             moc.insertarMaterial(m[i]);      j=j-m[i].getCantidad(); i--;}
       
       }
     }
  }

}

int max(int i,int j){
   if(j>i) return j;
   else return i;
 }


void CambioTiempo(){
  Clock time;
  SistemaMonetario sist;

   std::string nombre="../Euros.txt";
   std::ifstream fichero;
     fichero.open(nombre.c_str());

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
         std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
         return;}
  fichero>>sist;//se meten los datos del fichero
  fichero.close();
  
  std::cout<<"Introduce el incremento"<<std::endl;
  int n;
  std::cin>>n;
  std::cout<<"Introduce las repeticiones"<<std::endl;
  int rep;
  std::cin>>rep;
  if(n<1||rep<1){std::cout<<"Error"<<std::endl; return;}

  std::vector<std::vector <int> > monedasCamb;
  std::vector <int> solucion;

  std::vector <double> muestra;
  std::vector <double> tiempo;
  double tiempo_pasado;
  for(int i=50000;i<=100000;i=i+n){
   tiempo_pasado=0;
      muestra.push_back(i);
   for(int k=0;k<rep;k++){
      time.start();
      cambAlgDinam(sist,i,monedasCamb);
      getSolCambio(monedasCamb,sist,solucion);
      if (time.isStarted()){
          time.stop();
          tiempo_pasado+=time.elapsed();
         }
    }
    tiempo.push_back(tiempo_pasado/rep);
   } 
  std::vector<double> tiempo_estimado(muestra.size());
  std::vector<std::vector<double> > sol=calcularMinimosCuadrados(muestra, tiempo,2);
  std::ofstream file;
  file.open("FicheroCambio.txt");
  for(int i=0;i<muestra.size();i++){
     tiempo_estimado[i]=calcularValorAprox(muestra[i],sol,2);       
     file<<muestra[i]<<" "<<tiempo[i]<<" "<<tiempo_estimado[i]<<std::endl;}
     
  file.close();
  system("../graficaCambio.sh");
  std::cout<<"\nFunción de minimos cuadrados: "<<sol[1][0]<<"X+"<<sol[0][0]<<std::endl;
  std::cout<<"El coeficiente de determinación es de "<<determinacion(tiempo_estimado,tiempo)<<std::endl; 

 double valor=1;
 while(valor!=0){
    std::cout<<"\nIntroduce valor para estimar(n=0,salir):";
    std::cin>>valor;
    if(valor>0){
    std::cout<<"La estimacion del tiempo para ese valor es de ";
    TiempoAlgoritmos(calcularValorAprox(valor,sol,2));}
   }
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

  std::cout<<"Introduce el numero a cambiar en centimos"<<std::endl;
  int n;
  std::cin>>n;
  if(n<1){std::cout<<"Error"<<std::endl; return;}
  
  std::vector<std::vector <int> > monedasCamb;
  cambAlgDinam(sist,n,monedasCamb);
  std::vector<Moneda> sistema=getSistemaMonetario(sist);


  std::vector <int> solucion;
  
 
  if(getSolCambio(monedasCamb,sist,solucion)){
   std::cout<<BIBLUE<<"El cambio requiere:"<<RESET<<std::endl;
   for(int k=0;k<solucion.size();k++){
     if(solucion[k]!=0)
         std::cout<<solucion[k]<<" "<<sistema[k].getTipo()<<" de "<<sistema[k].getValor()<<" centimos\n";
   }
  }
  else
        std::cout<<"No tiene solucion"<<std::endl;
  std::cin.ignore();
  std::cin.ignore();
}





void cambAlgDinam(const SistemaMonetario &sist,int n, std::vector<std::vector <int> > &vectorCamb){
  std::vector<std::vector <int> > monedasCamb(sist.size(),std::vector<int>(n+1,0));
  std::vector<Moneda> sistema=getSistemaMonetario(sist);


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

bool getSolCambio(const std::vector<std::vector <int> > &monedasCamb,const SistemaMonetario &sist,std::vector<int> &sol){
   std::vector<Moneda> sistema=getSistemaMonetario(sist);
   std::vector<int> solucion(monedasCamb.size(),0);
   int i=monedasCamb.size()-1,j=monedasCamb[i].size()-1;
 
   if(monedasCamb[i][j]==-1) return false;
    while(j>0&&i>0){ 
     if(monedasCamb[i][j]==monedasCamb[i-1][j]) i--;
     else{
        if( monedasCamb[i][j]==1+monedasCamb[i][j-sistema[i].getValor()]){
             solucion[i]++;      j=j-sistema[i].getValor();
         }
       }
    }
   if(i==0&& monedasCamb[i][j]==1+monedasCamb[i][j-sistema[i].getValor()]){ solucion[0]+=monedasCamb[i][j];}
   sol=solucion;
   return true;
}

int min(int i,int j){
    if(i==-1) return j;
    if(j==-1) return i;
    if(j>i) return i;
    else return j;
}

std::vector<Moneda> getSistemaMonetario(SistemaMonetario sist){
   std::vector<Moneda> m_;
   sist.gotoFirstCursor();
   bool i=true;
   while(i==true){
     m_.push_back(sist.getCursor());
     i=sist.gotoNextCursor();
     }

   return m_;
}
