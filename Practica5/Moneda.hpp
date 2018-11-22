#ifndef MONEDA_HPP
#define MONEDA_HPP
#include <iostream>
#include <string>
using namespace std;
class Moneda{
  private:
    int valor_;
    string tipo_;
  public:
    void setValor(int i){valor_=i;}
    int getValor() const{return valor_;}
    void setTipo(string i){tipo_=i;}
    string getTipo() const{return tipo_;}

    friend  istream &operator>>(istream &stream,Moneda & moneda){
                                   string i; std::getline(stream,i,' ');
                                   if(!i.empty())moneda.valor_=stoi(i);
                                   std::getline(stream,i,'\n');
                                   moneda.setTipo(i);
                                   return stream;}
    friend  ostream &operator<<(ostream &stream,const Moneda & moneda){
                                   stream<<moneda.getValor(); return stream;}
    bool operator==(const Moneda &m) const{
                                   if(this->valor_==m.valor_) return true; return false;}
};



#endif
