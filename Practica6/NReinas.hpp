#ifndef NREINAS_HPP
#define NREINAS_HPP

#include <iostream>
#include <vector>
class NReinas{
  private:
    int cursor_;
    std::vector<int> solucion_;
    std::vector<ReinasExistentes> r_;
  public:
    NReinas(int n=8){
        solucion_.resize(n,0);cursor_=0;r_.resize(n,0);}
    bool esCorrecto();
    bool existeReina();
    int size(){return solucion_.size();}
    bool insertarReina(int i){solucion_[cursor_]=i;cursor++;}
    void eliminarReina();

    friend ostream &operator<<(ostream &stream,const NReinas n){
                                      for(int i=0;i<n.size();i++) ostream<<n.solucion_[i]<<" ";
                                      return stream;
                                      }   
}; 


struct ReinasExistentes{
   int nReina_;
   std::vector<int> reinasDisponibles_;
   int cursorReinasExistentes_;
}
#endif
