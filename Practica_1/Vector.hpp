#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <cstdlib>
#include <ctime>

class Vector{
   private:
    std::vector<int> v_;
    inline int getLeftChild(int i)const{
             #ifndef NDEBUG
                assert(i>=0);
             #endif
             return 2*i+1;
             }

    inline int getRightChild(int i)const{
             #ifndef NDEBUG
                assert(i>=0);
             #endif
             return 2*i+2;
             }


    inline int getParent(int i)const{
             #ifndef NDEBUG
               assert(i>=1);
             #endif
             return (i-1)/2;
             }

   public:
    Vector(int size){ 
         vector.resize(size,0);
         srand(time(NULL));
         }
    bool estaOrdenado();
    void rellenarVector();   
    void resize(int size){v_.resize(size);}
    void seleccion();
    void heapsort();    

 };

#endif
