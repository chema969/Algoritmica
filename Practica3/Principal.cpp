#include <string>
#include "Entero.hpp"

using namespace std;

int main(){
  string x,y;
  cout<<"Introduce el valor de ambos numeros separados por espacios"<<endl;
  cin>>x>>y;
  if(isInteger(x)&&isInteger(y)){
    Entero i(x);
    Entero j(y);
    Entero k=i*j;
    cout<<"El resultado es "<<k<<endl;
  } 
  else cout<<"Error, no son enteros"<<endl;
}
