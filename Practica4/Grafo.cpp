#include "Grafo.hpp"
#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip> 



void Grafo::createAdyacencia(){
      #ifndef NDEBUG
        assert(adyacencia_.empty());
      #endif
        adyacencia_.resize(vertices_.size());
        for(unsigned int i=0;i<adyacencia_.size();i++)
                        adyacencia_[i].resize(vertices_.size(),0);
        for(unsigned int i=0;i<lados_.size();i++){
                        adyacencia_[lados_[i].first()][lados_[i].second()]=1;
                        adyacencia_[lados_[i].second()][lados_[i].first()]=1;
                        }
         }
 


bool Grafo::adjacent(int u, int v)const{
   #ifndef NDEBUG
     assert(((unsigned int)u<vertices_.size())&&(u>=0));
     assert(((unsigned int)v<vertices_.size())&&(v>=0));  
   #endif 

       if(adyacencia_[u][v]!=0)	return true;
       return false;
  }




void Grafo::insertVertice(double x,double y){
     Vertice vertice;
     vertice.setX(x);
     vertice.setY(y);
     for(unsigned int i=0;i<vertices_.size();i++){
          if(vertice==vertices_[i]){
                      return;
                         }
              }
     vertice.setLabel(vertices_.size());
     vertices_.push_back(vertice);
     adyacencia_.resize(vertices_.size());
     for(unsigned int i=0;i<adyacencia_.size();i++){
           adyacencia_[i].resize(adyacencia_.size());
      }
      vertice_cursor_=vertices_.size()-1;
      }





void Grafo::insertLado(int u,int v){
      #ifndef NDEBUG
          assert(((unsigned int)u<vertices_.size())&&(u>=0));
          assert(((unsigned int)v<vertices_.size())&&(v>=0));
          assert(!adjacent(u,v));
      #endif 
      double x_value=pow(vertices_[u].getX()-vertices_[v].getX(),2);
      double y_value=pow(vertices_[u].getY()-vertices_[v].getY(),2);
      double peso=sqrt(x_value+y_value);
      Lado lado(u,v,peso);
      lados_.push_back(lado);
      adyacencia_[u][v]=1;
      adyacencia_[v][u]=1;
     lado_cursor_=lados_.size()-1;
    }


void Grafo::removeLado(){
      #ifndef NDEBUG
          assert(hasCurrentLado());
      #endif
      adyacencia_[lados_[lado_cursor_].first()][lados_[lado_cursor_].second()]=0;
      adyacencia_[lados_[lado_cursor_].second()][lados_[lado_cursor_].first()]=0;
      lados_[lado_cursor_]=lados_[(lados_.size()-1)];
      lados_.erase(lados_.end()-1);
      lado_cursor_=-1;
}

void Grafo::removeVertice(){
    int curs=vertice_cursor_;
    std::cout<<lados_.size();
    std::vector <Lado>::iterator it;
    for(it=lados_.begin();it!=lados_.end();++it){
         std::cout<<"Lados actualmente: "<<it->first()<<" y "<<it->second()<<" con peso "<<it->getPeso()<<std::endl;
         if(it->has(curs))
                  lados_.erase(it);
    }
    

    std::cout<<"Lados actualmente"<<std::endl;
    for(unsigned int i=0;i<lados_.size();i++)
       std::cout<<"Lado: une "<<lados_[i].first()<<" y "<<lados_[i].second()<<" con peso "<<lados_[i].getPeso()<<std::endl;

}
 

bool Grafo::findVertice(double x,double y){
      if(isEmpty())return false;
      Vertice vertice;
      vertice.setX(x);
      vertice.setY(y); 
      for(unsigned int i=0;i<vertices_.size();i++){
           if(vertice==vertices_[i]){
                          vertice_cursor_=i;
                          return true;
                            }
              }
      vertice_cursor_=-1;
      return false;
    }   



bool Grafo::findLado(int u,int v){
      if(lados_.empty())return false;
      if(!adjacent(u,v)){ 
                     lado_cursor_=-1;
                     return false;
                        }
      for(unsigned int i=0;i<lados_.size();i++){
               if((lados_[i].has(u))&&(lados_[i].other(u)==v)){
                                         lado_cursor_=i;
                                         return true; 
                                           }  
              }
  
      return false;
    }   


std::vector<std::vector<int> > Grafo::warshall()const{
#ifndef NDEBUG
   assert(!isEmpty());
#endif

    std::vector< std::vector<int> > path = adyacencia_;
    for(int k = 0; k < size(); k++){
        for(int i = 0; i < size(); i++){
            for(int j = 0; j < size(); j++){
                if(path[i][j]==0){
                   path[i][j]=path[i][k]*path[k][j];
                 }
            }
         }
    }
    return path;
}



Dijkstra Grafo::dijkstra(int origen){
#ifndef NDEBUG
   assert(size()>1);
   assert((origen>=0)&&(origen<size()));
#endif
     Dijkstra solucion;//Se crea un item de la clase Dijkstra
     solucion.distancias.resize(size());
     solucion.predecesores.resize(size(),origen);
     std::vector<bool> visitados;
     visitados.resize(size(),false);

     //Al principio se inicializa el vector de distancias con el peso de ese vertice a la distancia final y con el origen como predecesor
     for(int i=0;i<size();i++){
         if(findLado(origen,i)){
           solucion.distancias[i]=currentLado().getPeso();
          }
          else solucion.distancias[i]=std::numeric_limits<double>::infinity();
      }

     visitados[origen]=true;
 
     for(int i=0;i<size();i++){
        double min=std::numeric_limits<double>::infinity();
        int x=0;
        for(int j=0;j<size();j++){
           
          //Se coje la distancia minima no visitada
           if((visitados[j]==false)&&(solucion.distancias[j]<min)){
              min=solucion.distancias[j];
              x=j;
           }
         }
         visitados[x]=true;
        for(int j=0;j<size();j++){
          if(findLado(x,j)){
             //Si uno de los nodos no visitados reduce el peso de uno de los nodos sin visitar, este nuevo nodo pasa a ser el predecesor y modifica su peso
             if((visitados[j]==false)&&(solucion.distancias[j]>solucion.distancias[x]+currentLado().getPeso())){
                     solucion.distancias[j]=solucion.distancias[x]+currentLado().getPeso();
                     solucion.predecesores[j]=x;
              }
          }
        }
      }
    solucion.distancias[origen]=0;
    return solucion;
}






