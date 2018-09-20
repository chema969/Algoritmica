#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <cstdlib>
#include <ctime>

class Vector{
   private:
    std::vector<int> v_;
    void fnSortHeap(int arr2);
   public:
    Vector(int size=1){ 
         v_.resize(size,0);
         srand(time(NULL));
         }
    bool estaOrdenado();
    void rellenarVector();   
    void resize(int size){v_.resize(size);}
    void seleccion();
    void heapsort();    

 };

#endif
