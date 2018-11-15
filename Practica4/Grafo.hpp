#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"
#include <cassert>

struct Dijkstra{
   std::vector <double> distancias;
   std::vector <int> predecesores;
};


class Grafo{

   private:
        std::vector<std::vector<int> > adyacencia_;
        std::vector<Lado> lados_;
        std::vector<Vertice> vertices_;
        int vertice_cursor_;
        int lado_cursor_;



        void dropAdyacencia(){
                             for(unsigned int i=0;i<adyacencia_.size();i++) 
                                                            adyacencia_[i].clear();
                             adyacencia_.clear();
                              }


        void createAdyacencia();
        
        bool sortLados(Lado i,Lado j){return i.getPeso()<j.getPeso();}
       
   public:

         Grafo(){
             vertice_cursor_=-1;
             lado_cursor_=-1;
                }
 

        bool isEmpty()const{
                         return vertices_.empty();}

  
        int size()const{
                         return vertices_.size();}

        bool adjacent(int u, int v)const;


        bool hasCurrentVertice()const{
                          if(vertice_cursor_==-1) return false;
                          return true; 
                                    }


        Vertice currentVertice()const{
                            #ifndef NDEBUG
                               assert(hasCurrentVertice());
                            #endif
                             return vertices_[vertice_cursor_];}


        bool hasCurrentLado()const{
                          if(lado_cursor_==-1) return false;
                          return true; 
                                    }


        Lado currentLado()const{
                            #ifndef NDEBUG
                               assert(hasCurrentLado());
                            #endif
                             return lados_[lado_cursor_];}       
       
        bool estanUnidos(int i,int j)const{
                             std::vector<std::vector <int> > unidos=warshall();
                             if(unidos[i][j]==0)return false;
                             else return true;
                             }
        
        bool todosUnidos()const{
                             std::vector<std::vector <int> > unidos=warshall();
                             for(int i=0;i<size();i++){
                                  for(int j=0;j<size();j++){
                                       if(unidos[i][j]==0)return false;
                                   }
                             }
                             return true;}

 
       void insertVertice(double x,double y);

  
       void insertLado(int u, int v);


       void removeVertice();


       void removeLado();


       bool findVertice(double x,double y);

   
       void gotoVertice(int i){
                            #ifndef NDEBUG
                               assert(i>=0);
                               assert((unsigned int)i<vertices_.size());
                            #endif
                            vertice_cursor_=i;
                              } 


       void gotoFirstVertice(){
                             #ifndef NDEBUG
                                assert(!isEmpty());
                             #endif
                             vertice_cursor_=0;
                               }            
       

       bool gotoNextVertice(){
                            #ifndef NDEBUG
                               assert(hasCurrentVertice());
                            #endif
                             if((unsigned int)vertice_cursor_<vertices_.size()-1){
                                          vertice_cursor_++;
                                          return true;
                                          }
                              return false;
                              }


      bool findLado(int u,int v);

  
      void gotoLado(int i){
                            #ifndef NDEBUG
                               assert(i>=0);
                               assert((unsigned int)i<lados_.size());
                            #endif
                            lado_cursor_=i;
                              }    


       void gotoFirstLado(){
                             #ifndef NDEBUG
                                assert(!lados_.empty());
                             #endif
                             lado_cursor_=0;
                               }       


       bool gotoNextLado(){
                            #ifndef NDEBUG
                               assert(hasCurrentLado());
                            #endif
                             if((unsigned int)lado_cursor_<lados_.size()){ 
                                          lado_cursor_++;
                                          return true;}
                             return false;
                              }
                          
       void imprimir();
                              
};

#endif
