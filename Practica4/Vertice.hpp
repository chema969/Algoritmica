#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <string>

using namespace std;

class Vertice{
   private:
     int label_;
     string nombre_;     
   public:
     Vertice(string nombre="",int label=0){ nombre_=nombre; label_=label;}
     void setLabel(int label){label_=label;}
     void setNombre(string nombre){nombre_=nombre;} 
     int getLabel()const{return label_;}
     string getNombre()const {return nombre_;}
     friend  istream &operator>>(istream &stream,Vertice & vertice){
                                                     string i; std::getline(stream,i,'\n'); vertice.setNombre(i);return stream;}
     
     
};


#endif
