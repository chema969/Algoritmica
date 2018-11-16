#ifndef LADO_HPP
#define LADO_HPP

#include <cassert>

class Lado{
     private:
      double peso_;
      int vertice1_;
      int vertice2_;
     public:
   
      Lado(int vertice1,int vertice2,double peso=0.0){
                          vertice1_=vertice1;
                          vertice2_=vertice2;
                          peso_=peso;
                            }
    
      double getPeso()const{return peso_;}


      bool has(int vertex)const{
                   if((vertice1_==vertex) || (vertice2_==vertex)) 
                                   return true;
                    return false;                         
                    }


      int first() const{return vertice1_;}


      int second()const{return vertice2_;}


      int other(int i)const;     
 

      void setPeso(double i){
                           
                             assert(i>=0);

                         peso_=i;
                         }







   
     };
     

#endif
