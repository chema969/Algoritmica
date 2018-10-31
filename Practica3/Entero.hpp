#ifndef ENTERO_HPP
#define ENTERO_HPP
#include <string>
#include <cassert>

class Entero{
  private:
    std::string entero_;
    bool isInteger(const std::string & s);
  public:
    Entero(const std::string &entero){
         assert(isInterter(entero))
         entero_=entero;
       }

    void setEntero(const std::string &entero){
                                          assert(isInterter(entero))
                                          entero_=entero;}

    std::string getEntero(){return entero_;}

    void partirCadena(std::string &c1, std::string &c2);

    void agregarCerosFinal(int nCeros);

    void agregarCerosDelante(int nCeros);

    void quitarCerosNoSignificativos();

    void multiplicarPotencia10(int potencia);

    friend ostream &operator<<(ostream &salida,const Entero &d);
  };



#endif
