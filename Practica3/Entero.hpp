#ifndef ENTERO_HPP
#define ENTERO_HPP
#include <string>
#include <cassert>
#include <iostream>

 bool isInteger(const std::string & s);
class Entero{
  private:
    std::string entero_;
    int max_;
    bool negative;
    int mayorMagnitud(const Entero &v){ 
                      if(v.getEntero().length()>=entero_.length())return v.getEntero().length();
                      else return entero_.length();}
  public:
    Entero(const std::string &entero,int max=4){
         negative=false;
         setEntero(entero);
         setMax(max);
       }
    void setMax(int max){max_=max;}
    void setEntero(const std::string &entero){
                                          assert(isInteger(entero));
                                          entero_=entero;
                                          if(entero[0]=='-')negative=true;}
    int getMax(){ return max_;}
    std::string getEntero()const{return entero_;}

    void partirCadena(std::string &c1, std::string &c2);

    void agregarCerosFinal(int nCeros);

    void agregarCerosDelante(int nCeros);

    void quitarCerosNoSignificativos();

    void multiplicarPotencia10(int potencia);

    friend std::ostream &operator<<(std::ostream &salida,const Entero &d);

    friend std::istream &operator>>(std::istream &salida, Entero &d);

    Entero operator+(Entero &e);

    Entero operator*(Entero &e);
 
    void operator=(const Entero &e){ this->entero_=e.entero_;}
  };



#endif
