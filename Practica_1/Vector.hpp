#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <cstdlib>
#include <ctime>

class Vector{
   private:
    std::vector<int> v_;
   public:
    Vector(int size){ 
         vector.resize(size,0);
         srand(time(NULL));
         }
    bool estaOrdenado();
    void rellenarVector();   
  












 };

#endif
