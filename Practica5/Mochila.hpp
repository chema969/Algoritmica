#ifndef MOCHILA_HPP
#define MOCHILA_HPP

#include "Material.hpp"
#include <iostream>
#include <vector>
using namespace std;
class Mochila{
    private:
      int capacidad_;
      int pesoActual_;
      vector<Material> mat_;
    public:
      Mochila(int cap=0){
                capacidad_=cap; pesoActual_=0;}
      void setCapacidad(int capacidad){capacidad_=capacidad;}
      int getCapacidad()const{return capacidad_;}
      bool insertarMaterial(Material m);
      int getCapacidadRestante(){return capacidad_-pesoActual_;}
       friend  ostream &operator<<(ostream &stream,const Mochila & moc){
                             for(int i=0;i<moc.mat_.size();i++) stream<<moc.mat_[i]<<"\n";       
                             return stream;}

};

#endif
