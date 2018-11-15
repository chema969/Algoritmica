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
     int getLabel(){return label_;}
     string getNombre(){return nombre_;}

}


#endif
