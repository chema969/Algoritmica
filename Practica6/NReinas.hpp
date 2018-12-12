#ifndef NREINAS_HPP
#define NREINAS_HPP

#include <iostream>
#include <vector>
class NReinas{
  private:
    std::vector<int> solucion_;
  public:
    NReinas(int n=8){
        solucion_.resize(n,0);}
    bool esCorrecto();
    bool existeReina();
    int getValor(int x)const{return solucion_[x];}
    int size()const{return solucion_.size();}
    void setReina(int pos,int i){solucion_[pos]=i;}
    void eliminarReina(int pos);
    bool lugar(int lug);
    void vaciarReinas();
    void print(){ for(int i=0;i<size();i++) std::cout<<solucion_[i]<<" ";std::cout<<std::endl;}
    friend std::ostream &operator<<(std::ostream &stream,const NReinas n){
                                      for(int i=0;i<n.size();i++) stream<<n.solucion_[i]<<" ";
                                      return stream;
                                      }   
    void operator=(const NReinas &xd){
                              this->solucion_=xd.solucion_;
                            }
}; 



#endif
