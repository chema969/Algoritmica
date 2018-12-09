#include "NReinas.hpp"
#include <vector.hpp>

bool NReinas::esCorrecto(){
   for(int i=1;i<solucion_.size();i++){
      for(int j=0;j<solucion_.size();j++){
        if(solucion_[i]==solucion_[j]||solucion_[i]==solucion_[j]-(i-j)||solucion_[i]==solucion_[j]+(i-j)) return false; 
      }
   }
   return true;
}


bool NReinas::existeReina(){
    std::vector<bool> reinasExistentes(size(),true);
    for(int i=0;i<cursor_;i++){
    }
}


bool NReinas::insertarReina(int i){
    solucion_[cursor_]=i;
    cursor++;
    if(cursor>=size())return false;
    else return true;
    }


void eliminarReina(){
   if(cursor_>0){
    solucion_[cursor_-1]=0;
    cursor--;
   }
}
