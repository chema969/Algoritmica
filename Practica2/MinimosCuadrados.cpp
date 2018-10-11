#include <vector>
#include "MinimosCuadrados.hpp"
#include <fstream>
#include <cmath>
#include <cassert>
#include <cstdlib>

std::vector< std::vector< double> > calcularMinimosCuadradosTerminosInd(std::vector<double> tamanyo,std::vector<double>tiempo,int n){
   std::vector< std::vector< double> > minimosCuadradosTerminosInd;

   minimosCuadradosTerminosInd.resize(n);
   for(int i=0;i<n;i++) minimosCuadradosTerminosInd[i].resize(1,0);

   for(int i=0;i<n;i++)
         minimosCuadradosTerminosInd[i][0]=sumatorioMultValores(tamanyo,tiempo,i);

   return minimosCuadradosTerminosInd;
}









double sumatorioMultValores(std::vector<double> tamanyo,std::vector<double> tiempo,double n){
    assert(tiempo.size()==tamanyo.size());
    double aux=0;

    for(unsigned int i=0;i<tiempo.size();i++)
        aux+=(tiempo[i]*pow(tamanyo[i],n));


    return aux;


}


double media(std::vector<double> v){
   double media=0;
   for(unsigned int i=0;i<v.size();i++){
     media+=v[i];
   }
   return media/v.size();
}





double desviacionTipica(std::vector<double> v){
    double medias=media(v);
    double aux=0;
    for(unsigned int i=0;i<v.size();i++)
        aux+=pow(v[i]-medias,2);
    aux=aux/v.size();
    aux=sqrt(aux);
    return aux;
   }



double varianza(std::vector<double> v){

    double medias=media(v);


    double aux=0;

    for(unsigned int i=0;i<v.size();i++)
        aux+=(pow(v[i]-medias,2)/v.size());

    aux=aux-pow(medias,2);

    return aux;
   }




double covarianza(std::vector<double> v1,std::vector<double> v2){
    double mediaV1=media(v1);
    double mediaV2=media(v2);
    double sumV1V2=sumatorioMultValores(v1,v2,1);

    double covarianzas=sumV1V2/v1.size();
    covarianzas=covarianzas-mediaV1*mediaV2;
    return covarianzas;
}




double determinacion(std::vector<double> aprox,std::vector<double> tiempo){

    double varianzaAprox=varianza(aprox);
    double varianzaTiempo=varianza(tiempo);

    return (varianzaAprox/varianzaTiempo);
}









std::vector < std::vector< double> > calcularMinimosCuadrados(std::vector<double> tamanyo,int n){
   std::vector< std::vector< double> > minimosCuadrados;
   minimosCuadrados.resize(n);
   for(int i=0;i<n;i++)     minimosCuadrados[i].resize(n,0);


   for(double i=0;i<n;i++){
      for(double j=0;j<n;j++){
          minimosCuadrados[i][j]=minimosCuadrados[j][i]=sumaVector(tamanyo,j+i);
      }
   }


   return minimosCuadrados;
}










double sumaVector(std::vector<double> vector,double exponente){
     double aux=0;
      for(unsigned int i=0;i<vector.size();i++) aux+=pow(vector[i],exponente);
     return aux;
}



double calcularValorAprox(int valorAprox,std::vector < std::vector <double> > soluciones,double n){
    if(valorAprox>0){
         double valor=0;
         for(int i=0;i<n;i++){
           valor+=soluciones[n][0]*pow(valorAprox,i);
         }  
     }
   return valor;
}
