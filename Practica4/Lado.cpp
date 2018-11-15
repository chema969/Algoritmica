#include "Lado.hpp"




   int Lado::other(int i)const{
               if(!has(i)) return -1;
               if(i==vertice1_){
                      return vertice2_;
                           }
               else
                      return vertice1_;
               }













