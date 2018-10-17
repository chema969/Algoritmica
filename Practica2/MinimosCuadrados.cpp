#include <vector>
#include "MinimosCuadrados.hpp"
#include <cmath>
#include <cassert>
#include <cstdlib>
#include "sistemaEcuaciones.hpp"


std::vector< std::vector< double> > calcularMinimosCuadrados(const std::vector<double> &tamanyo,const std::vector<double> &tiempo,int n){

  std::vector< std::vector< double> > matrizDeCoeficientes= calcularMinimosCuadradosTerminosDep(tamanyo ,n);
  std::vector< std::vector< double> > matrizDeTerminosIndependientes= calcularMinimosCuadradosTerminosInd(tamanyo,tiempo,n);


  std::vector< std::vector< double> > soluciones;
  soluciones.resize(n);
   for(int i=0;i<n;i++)     soluciones[i].resize(1,0);

  resolverSistemaEcuaciones(matrizDeCoeficientes, matrizDeTerminosIndependientes, n, soluciones);

  return soluciones;



}



std::vector< std::vector< double> > calcularMinimosCuadradosTerminosInd(const std::vector<double> &tamanyo,const std::vector<double> &tiempo,int n){
   std::vector< std::vector< double> > minimosCuadradosTerminosInd;

   minimosCuadradosTerminosInd.resize(n);
   for(int i=0;i<n;i++) minimosCuadradosTerminosInd[i].resize(1,0);

   for(int i=0;i<n;i++)
         minimosCuadradosTerminosInd[i][0]=sumatorioMultValores(tamanyo,tiempo,i);

   return minimosCuadradosTerminosInd;
}









double sumatorioMultValores(const std::vector<double> &tamanyo,const std::vector<double> &tiempo,double n){
    assert(tiempo.size()==tamanyo.size());
    double aux=0;

    for(unsigned int i=0;i<tiempo.size();i++)
        aux+=(tiempo[i]*pow(tamanyo[i],n));


    return aux;


}


double media(const std::vector<double> &v){
   double media=0;
   for(unsigned int i=0;i<v.size();i++){
     media+=v[i];
   }
   return media/v.size();
}





double desviacionTipica(const std::vector<double> &v){
    double medias=media(v);
    double aux=0;
    for(unsigned int i=0;i<v.size();i++)
        aux+=pow(v[i]-medias,2);
    aux=aux/v.size();
    aux=sqrt(aux);
    return aux;
   }



double varianza(const std::vector<double> &v){

    double medias=media(v);


    double aux=0;

    for(unsigned int i=0;i<v.size();i++)
        aux+=(pow(v[i]-medias,2)/v.size());

    aux=aux-pow(medias,2);

    return aux;
   }




double covarianza(const std::vector<double> &v1, const std::vector<double> &v2){
    double mediaV1=media(v1);
    double mediaV2=media(v2);
    double sumV1V2=sumatorioMultValores(v1,v2,1);

    double covarianzas=sumV1V2/v1.size();
    covarianzas=covarianzas-mediaV1*mediaV2;
    return covarianzas;
}




double determinacion(const std::vector<double> &aprox,const std::vector<double> &tiempo){

    double varianzaAprox=varianza(aprox);
    double varianzaTiempo=varianza(tiempo);

    return (varianzaAprox/varianzaTiempo);
}









std::vector < std::vector< double> > calcularMinimosCuadradosTerminosDep(const std::vector<double> &tamanyo,int n){
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










double sumaVector(const std::vector<double> &vector,double exponente){
     double aux=0;
      for(unsigned int i=0;i<vector.size();i++) aux+=pow(vector[i],exponente);
     return aux;
}



double calcularValorAprox(int valorAprox,const std::vector < std::vector <double> > &soluciones,int n){
    if(valorAprox>0){
         double valor=0;
         for(int i=0;i<n;i++){
           valor+=soluciones[i][0]*pow(valorAprox,i);
         }
        return valor;  
     }
    else return -1;
}
