#include "FuncionesAuxiliares.hpp"
#include "Lado.hpp"
#include "Vertice.hpp"
#include "macros.hpp"
#include "SistemaMonetario.hpp"
#include <iostream>
#include "Grafo.hpp"
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


void ViajanteDeComercio(){
   Grafo grafo;
   //std::cout<<"Introduce el fichero con los vertices:"<<std::endl;
   std::string nombre="../Andalucia.txt";
   //std::cin>>nombre;
   std::ifstream fichero;
     fichero.open(nombre.c_str());

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
         std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
         return;}
 
     Vertice aux;
     while(fichero>>aux){
          if(!grafo.findVertice(aux.getNombre()))
             grafo.insertVertice(aux.getNombre());
    }
      fichero.close();

    //std::cout<<"Introduce el fichero con los lados y el resto de datos:"<<std::endl;
   // std::cin>>nombre;
    nombre="../matrizAndaluciaCompleta.txt";
    fichero.open(nombre.c_str());

   //Prueba si el fichero se abrió bien
     if(!fichero.good()){
         std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
         return;}

     int size;
     fichero>>size;

     if(size!=grafo.size()){
         std::cout<<BIRED<<"El tamaño debe ser el mismo"<<RESET<<std::endl;
         return;
        }

     int dir;
     fichero>>dir;
     grafo.setDirigido(dir>0);
     
     for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
        int lado;
        fichero >> lado;
        if(lado>0){
          if(!grafo.adjacent(i,j))
            grafo.insertLado(i,j,lado);
        }
       }
     }
   Grafo solucion(dir>0);
   Viajante(grafo,solucion);
   solucion.imprimir();
   std::cout<<"El peso total del arbol abarcador de coste minimo es "<<solucion.getPesoTotal()<<std::endl;
   std::cin.ignore();
   std::cin.ignore();
}



void Viajante(Grafo &grafo,Grafo &solucion){
    grafo.sortLados();
    grafo.gotoFirstVertice();
    do{
     solucion.insertVertice(grafo.currentVertice().getNombre());
    }while( grafo.gotoNextVertice());
    int l=0;
    std::vector< Grafo > conjuntos(grafo.size());

    grafo.gotoFirstVertice();
    for(int i=0;i<grafo.size();i++){
       conjuntos[i].insertVertice(grafo.currentVertice().getNombre());
        grafo.gotoNextVertice();
   }

   grafo.gotoFirstLado();
    do{
     Lado lad=grafo.currentLado();
     grafo.gotoVertice(lad.first());

     std::string first(grafo.currentVertice().getNombre());


     grafo.gotoVertice(lad.second());
     std::string sec=grafo.currentVertice().getNombre();

     int conjunto1=-1,conjunto2=-1;
    for(int i=0;(i<conjuntos.size()&&(conjunto1==-1||conjunto2==-1));i++){
        if(conjuntos[i].findVertice(first)) conjunto1=i;
        if(conjuntos[i].findVertice(sec)) conjunto2=i;
     } 
     assert(conjunto1!=-1&&conjunto2!=-1);        
      if(conjunto1!=conjunto2){
        conjuntos[conjunto1].findVertice(first);
        conjuntos[conjunto2].findVertice(sec);
       if(conjuntos[conjunto1].numLadoCurrVertice()<2&&conjuntos[conjunto2].numLadoCurrVertice()<2){
       conjuntos.push_back(unirConjuntos(conjuntos[conjunto1],conjuntos[conjunto2],first,sec,lad.getPeso()));
       if(conjunto1>conjunto2){
           conjuntos.erase(conjuntos.begin()+conjunto1);
           conjuntos.erase(conjuntos.begin()+conjunto2);
        }
       else{
           conjuntos.erase(conjuntos.begin()+conjunto2);
           conjuntos.erase(conjuntos.begin()+conjunto1);
       }
       l++;
      }
     }
    }while(l<grafo.size()-1&&grafo.gotoNextLado());
   
   solucion=conjuntos[conjuntos.size()-1];
   std::vector<int> ultLado(2,-1);
   std::vector<std::string> nombreLado(2,"p");
   int q=0;
   solucion.gotoFirstVertice();

   do{
     if(solucion.numLadoCurrVertice()<2){
                   ultLado[q]=solucion.getCurrentCursor(); 
                   nombreLado[q]=solucion.currentVertice().getNombre();q++;}

   }while(solucion.gotoNextVertice()&&(ultLado[0]==-1||ultLado[1]==-1));

   assert(ultLado[0]!=-1&&ultLado[1]!=-1);
   grafo.findVertice(nombreLado[0]);
   int i=grafo.getCurrentCursor();
   grafo.findVertice(nombreLado[1]);
   int j=grafo.getCurrentCursor();
   
   grafo.findLado(i,j);
   solucion.insertLado(ultLado[0],ultLado[1],grafo.currentLado().getPeso());
}


Grafo unirConjuntos( Grafo &a, Grafo &b,std::string i,std::string j,int peso){
    Grafo g;
    a.gotoFirstVertice();
     do{
     g.insertVertice(a.currentVertice().getNombre());
    }while( a.gotoNextVertice());
    
    b.gotoFirstVertice();
    do{
       g.insertVertice(b.currentVertice().getNombre());
    }while( b.gotoNextVertice());
   
    if(a.hasLados()){ 
    a.gotoFirstLado();
    do{
      Lado lad=a.currentLado();
      g.insertLado(lad.first(),lad.second(),lad.getPeso());
    }while(a.gotoNextLado());
    }

    if(b.hasLados()){
    b.gotoFirstLado();
    do{
      Lado lad=b.currentLado();
      g.insertLado(lad.first()+a.size(),lad.second()+a.size(),lad.getPeso());
    }while(b.gotoNextLado());
    }
    g.findVertice(i);
    int aux1=g.getCurrentCursor();
    g.findVertice(j);
    g.insertLado(aux1,g.getCurrentCursor(),peso);
    return g;
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
  
  std::vector <int> cantMonedas;
  std::vector <Moneda> solucion;
  int s=n;
  int lastMoneda=sist.getSistemaMonetario()[sist.size()-1].getValor()+1;
  while(s!=0){
      if(!sist.setMaximo(s)){
              std::cout<<"NO existe solucion al problema"<<std::endl;
              return;}
      else{
         Moneda aux=sist.getMaximo();
         s=s-aux.getValor();
         if(aux.getValor()<lastMoneda){
            lastMoneda=aux.getValor();
            solucion.push_back(aux);
            cantMonedas.push_back(1);
         }
         else{
           cantMonedas[cantMonedas.size()-1]++;
         }
       }
  }  
  std::cout<<BIBLUE<<"El cambio requiere:"<<RESET<<std::endl;
  for(int i=0;i<cantMonedas.size();i++)
      std::cout<<cantMonedas[i]<<" "<<solucion[i].getTipo() <<" de "<<solucion[i].getValor()<<std::endl;
  std::cin.ignore();
  std::cin.ignore();
}
