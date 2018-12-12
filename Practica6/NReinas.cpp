#include "NReinas.hpp"
#include <vector>
#include <cstdlib>
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
    for(int i=1;i<=size();i++){
      if(lugar(i)) return true; 
    }
   return false;
}




void NReinas::eliminarReina(int pos){
   solucion_[pos]=0;
}



bool NReinas::lugar(int lug){
    for(int j=0;j<lug;j++){
        if(solucion_[j]==solucion_[lug]||abs(solucion_[j]-solucion_[lug])==abs(j-lug)) return false; 
     }
    return true;


}

void NReinas::vaciarReinas(){
    for(int i=0;i<size();i++) solucion_[i]=0;
}
