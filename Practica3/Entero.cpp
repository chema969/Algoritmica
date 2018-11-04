#include <cstdlib>
#include <iostream>
#include <string>
#include "Entero.hpp"


 bool isInteger(const std::string & s)
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
        if(entero_=="") entero_="0";

}
           
void Entero::multiplicarPotencia10(int potencia)
{
	agregarCerosFinal(potencia);
}	


std::ostream &operator<<(std::ostream &salida,const Entero &d){
   salida<<d.getEntero();
   return salida;
 }

std::istream &operator>>(std::istream &salida, Entero &d){
  std::string i;
   salida>>i;
   d.setEntero(i);
   return salida;
 }

Entero Entero::operator+( Entero &e){
       std::string suma;
       std::string::reverse_iterator j;
       std::string::reverse_iterator i;
       int acarreo=0;
       for(i=e.entero_.rbegin(),j=this->entero_.rbegin();(i!=e.entero_.rend())&&(j!=this->entero_.rend());i++,j++){
        int x = *i - '0';
	int y = *j - '0';
	
	int aux = x + y + acarreo;
	
	std::string aux2;
	if (aux < 10)
	{
		aux2 = '0' + aux;
                acarreo=0;
	}
	else
	{
		aux2 = '0' + aux % 10;
		acarreo = aux/10;
	}
        suma= aux2+suma;
       }
    
       while(i!=e.entero_.rend()){
          int aux;
          if(acarreo!=0){
            aux = (*i - '0') + acarreo;
            if (aux < 10) acarreo=0;
            else
	        {
		acarreo = aux/10;
	        aux=aux%10;
                 }
            
          }
          else
            suma=*i+suma;
          i++;
          }
         while(j!=this->entero_.rend()){
          int aux;
          if(acarreo!=0){
            aux = (*j - '0') + acarreo;
            if (aux < 10) acarreo=0;
            else
	        {
		acarreo = aux/10;
	        aux=aux%10; 
                 }
              std::string aux2;
              aux2='0'+aux;
             suma=aux2+suma ;   
          }
          else
            suma=*j+suma;
          j++;
          }
       if(acarreo>0){
         std::string aux2;
         aux2='0'+acarreo;
         suma=aux2+suma;
       }
       return Entero(suma);
}







Entero Entero::operator*( Entero &e){
    int n=this->mayorMagnitud(e);
    if(n<=4) 
       return Entero(std::to_string(std::stoi(e.entero_)*std::stoi(this->entero_)));
    if((this->entero_=="0")||(e.entero_=="0")) return Entero("0");
    
    if(n>this->entero_.length())   
         this->agregarCerosDelante(n-this->entero_.length());
    if(n>e.entero_.length())    
         e.agregarCerosDelante(n-e.entero_.length());

    int s=n/2;



    std::string w , x , y , z;
    this->partirCadena(w,x);
    e.partirCadena(y,z);
    Entero W(w);
    Entero X(x);
    Entero Y(y); 
    Entero Z(z);
   

    W.quitarCerosNoSignificativos(); X.quitarCerosNoSignificativos(); Y.quitarCerosNoSignificativos(); Z.quitarCerosNoSignificativos();
    Entero a= (W*Y);
    a.multiplicarPotencia10(s*2);

    Entero b=W*Z;
    Entero c=X*Y;
    Entero f=b+c;
    f.multiplicarPotencia10(s);
    Entero d=X*Z;
    Entero bb=a+f+d;
  
    bb.quitarCerosNoSignificativos();e.quitarCerosNoSignificativos();this->quitarCerosNoSignificativos();
    return bb;
   }
