#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <cassert>
#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"


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
        bool dirigido_;


        void dropAdyacencia(){
                             for(unsigned int i=0;i<adyacencia_.size();i++) 
                                                            adyacencia_[i].clear();
                             adyacencia_.clear();
                              }


        void createAdyacencia();
        
        static bool sortFunct(Lado i,Lado j){return i.getPeso()<j.getPeso();}
       
   public:

         Grafo(bool dir=false){
             vertice_cursor_=-1;
             lado_cursor_=-1;
             dirigido_=dir;
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
                            
                               assert(hasCurrentVertice());
                            
                             return vertices_[vertice_cursor_];}


        bool hasCurrentLado()const{
                          if(lado_cursor_==-1) return false;
                          return true; 
                                    }


        Lado currentLado()const{
                            
                               assert(hasCurrentLado());
                            
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

       void setDirigido(bool a){dirigido_=a;}       


       void insertVertice(std::string nombre);

  
       void insertLado(int u, int v,int distancia);


       void removeVertice();


       void removeLado();


       bool findVertice(std::string a);

   
       void gotoVertice(int i){

                               assert(i>=0);
                               assert((unsigned int)i<vertices_.size());
                            
                            vertice_cursor_=i;
                              } 


       void gotoFirstVertice(){
                             
                                assert(!isEmpty());
                             
                             vertice_cursor_=0;
                               }            
       

       bool gotoNextVertice(){
                            
                               assert(hasCurrentVertice());
                            
                             if((unsigned int)vertice_cursor_<vertices_.size()-1){
                                          vertice_cursor_++;
                                          return true;
                                          }
                              return false;
                              }


      bool findLado(int u,int v);

  
      void gotoLado(int i){
                            
                               assert(i>=0);
                               assert((unsigned int)i<lados_.size());
                            
                            lado_cursor_=i;
                              }    


       void gotoFirstLado(){
                             
                                assert(!lados_.empty());
                             
                             lado_cursor_=0;
                               }       


       bool gotoNextLado(){
                            
                               assert(hasCurrentLado());
                            
                             if((unsigned int)lado_cursor_<lados_.size()){ 
                                          lado_cursor_++;
                                          return true;}
                             return false;
                              }
                          
       void imprimir();


       void sortLados();

       
       std::vector<std::vector<int> > warshall()const;


       Dijkstra dijkstra(int origen);

       Grafo operator=(const Grafo b){this->adyacencia_=b.adyacencia_;
        this->lados_=b.lados_;
        this->vertices_=b.vertices_;
        this->vertice_cursor_=b.vertice_cursor_;
        this->lado_cursor_=b.lado_cursor_;
        this->dirigido_=b.dirigido_;
        return *this;}
                              
};

#endif
