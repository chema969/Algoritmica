#include <vector>
#include "vector.hpp"
#include <cstdlib>

bool Vector::estaOrdenado(){
   for(unsigned int i=1;i<v_.size();i++){
       if(v_[i]<v_[i-1]) return false;
      } 
   return true;
}

  
void Vector::rellenarVector(){
   for(unsigned int i=0;i<v_.size();i++){ 
      v_[i]=rand()%10000;
    }
}
