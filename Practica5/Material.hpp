#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
using namespace std;

class Material{
  private:
    int etiqueta_;
    int cantidad_;
    double precio_;
  public:
     Material(int etiqueta=0,int cantidad=0,double precio=0){
                 etiqueta_=etiqueta;cantidad_=cantidad;precio_=precio;}
     void setEtiqueta(int etiqueta){etiqueta_=etiqueta;}
     void setCantidad(int cantidad){cantidad_=cantidad;}
     void setPrecio(double precio){precio_=precio;}
     int getEtiqueta()const {return  etiqueta_;}
     int getCantidad()const {return cantidad_;}
     double getPrecio()const {return precio_;}
     Material cogerParte(int parte){cantidad_=cantidad_-parte; return Material(etiqueta_,parte,precio_);}
     friend  istream &operator>>(istream &stream,Material & mat){
                                   stream>>mat.etiqueta_>>mat.cantidad_>>mat.precio_;return stream;}
     friend  ostream &operator<<(ostream &stream,const Material & mat){
                                   stream<<mat.getEtiqueta()<<" "<<mat.getCantidad()<<" "<<mat.getPrecio(); return stream;}

};



#endif
