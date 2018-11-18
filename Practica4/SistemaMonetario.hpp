#ifndef SISTEMA_MONETARIO_HPP
#define SISTEMA_MONETARIO_HPP
#include <vector>
#include <iostream>
#include <algorithm>
#include "Moneda.hpp"

using namespace std;
//Clase que tiene un sistema monetario siempre ordenado de menor a mayor valor de monedas
class SistemaMonetario{
   private:
     vector <Moneda> sistemaMonetario_;
     int cursor_max_;
     static bool sortFunct(Moneda i,Moneda j){return i.getValor()<j.getValor();}
   public:
     SistemaMonetario(){
            cursor_max_=-1;}

     void insertMoneda(const Moneda m){ sistemaMonetario_.push_back(m);sortMonedas(); }

     bool borrarMoneda(const Moneda m){ for(int i=0;i<sistemaMonetario_.size();i++){
                                       if(m==sistemaMonetario_[i]){
                                           sistemaMonetario_.erase(sistemaMonetario_.begin()+i); return true;}
                                   }
                                   return false;}
     
     int size()const{ return sistemaMonetario_.size();}
    
     vector <Moneda> getSistemaMonetario()const{ return sistemaMonetario_;}

     void sortMonedas(){sort(sistemaMonetario_.begin(),sistemaMonetario_.end(),sortFunct);}
     
     bool setMaximo(int k){//Pone el cursor al maximo cambio que puede ofrecer para un valor k
                     cursor_max_=-1;
                     for(int i=sistemaMonetario_.size()-1;i>=0;i--){
                            if(sistemaMonetario_[i].getValor()<=k){
                                      cursor_max_=i; return true;}
                            }
                      
                      return false;}
  
     Moneda getMaximo(){return sistemaMonetario_[cursor_max_];}
  
     friend  istream &operator>>(istream &stream,SistemaMonetario & sist){
                                                     Moneda m;
                                                       while(stream>>m)sist.insertMoneda(m);
                                                          return stream;
                                                          }

     friend  ostream &operator<<(ostream &stream,const SistemaMonetario & moneda){
                                      for(int i=0;i<moneda.sistemaMonetario_.size();i++)     
                                                 stream<<i<<": "<<moneda.sistemaMonetario_[i]<<"\n";
                                       return stream;}



};

#endif
