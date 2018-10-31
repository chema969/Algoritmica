#include <cstdlib>
#include <string>
#include "Entero.hpp"


 bool Entero::isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}


void Entero::partirCadena( std::string &c1, std::string &c2)
{
	int n;
	int n1;
	
	n = entero_.length();
	
	if (n % 2 == 0) //n es par
	{
		n1 = n / 2;
	}
	else
	{
		n1 = (n + 1) / 2;
	}
	
	c1=entero_.substr(0,n1);
        c2=entero_.substr(n1);
}

void Entero::agregarCerosFinal( int nCeros)
{
     for (int i=0;i<nCeros;i++) entero_.push_back('0');       
}


void Entero::agregarCerosDelante( int nCeros){
     std::string aux;
     for (int i=0;i<nCeros;i++) aux.push_back('0');
     entero_=aux+entero_;
}


void Entero::quitarCerosNoSignificativos()
{
	int l, i = 0,numeroCeros=0;
	 
	l = entero_.length() -1;
	
       while(entero_[i] == '0' && i < l)
	{
		i++;
		numeroCeros++;
	}
        entero_=entero_.substr(numeroCeros);
}
           
void Entero::multiplicarPotencia10(int potencia)
{
	agregarCerosFinal(aux, potencia);
}	


ostream &operator<<(ostream &salida,const Entero &d){
   salida<<d.getEntero();
   return salida;
 }

