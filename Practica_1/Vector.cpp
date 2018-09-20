#include <vector>
#include "Vector.hpp"
#include <cstdlib>
#include <cassert>

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


void Vector::seleccion(){
   for(unsigned int i=0;i<v_.size();i++){
     int aux=v_[i];
     int aux_pos=i;
     
     for(unsigned int j=i+1;j<v_.size();j++){
       if(v_[j]<aux){
         aux=v_[j];
         aux_pos=j;
       }
     }
     v_[aux_pos]=v_[i];
     v_[i]=aux;
   }  
   assert(estaOrdenado());
}


void Vector::heapsort(){
    for(unsigned int i=v_.size(); i>1; i--){
       fnSortHeap( i - 1);
      }
     assert(estaOrdenado());
}



 void Vector::fnSortHeap (int arr2){
        int i, o;
        int lCh, rCh, mCh, root, tmp;
        root = (arr2-1)/2;

         for(o = root; o >= 0; o--){
              for(i=root;i>=0;i--){
                    lCh = (2*i)+1;
                    rCh = (2*i)+2;
                      if((lCh <= arr2) && (rCh <= arr2)){
                            if(v_[rCh] >= v_[lCh]){
                                mCh = rCh;
                               }
                             else{
                                 mCh = lCh;
                                }
                              }
                       else{
                            if(rCh > arr2){
                                mCh = lCh;
                                    }
                            else{
                               mCh = rCh;
                                    }
                              }

                              if(v_[i] < v_[mCh])
                              {
                                    tmp = v_[i];
                                    v_[i] = v_[mCh];
                                    v_[mCh] = tmp;
                              }
                        }
                  }
                  tmp = v_[0];
                  v_[0] = v_[arr2];
                  v_[arr2] = tmp;
                  return;
            }
 

