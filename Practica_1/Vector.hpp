#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Vector{
   private:
    std::vector<int> v_;
   public:
    Vector(int size=1){ 
         v_.resize(size,0);
         srand(time(NULL));
         }
    bool estaOrdenado();
    void rellenarVector();   
    void resize(int size){v_.resize(size);}
    void seleccion();
    void heapify(){std::make_heap(v_.begin(),v_.end());}
    void heapsort();    

 };

#endif
