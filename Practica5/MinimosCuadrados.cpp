#include <vector>
#include "MinimosCuadrados.hpp"
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <string>
#include "sistemaEcuaciones.hpp"


std::vector< std::vector< double> > calcularMinimosCuadrados(const std::vector<double> &tamanyo,const std::vector<double> &tiempo,int n){

  std::vector< std::vector< double> > matrizDeCoeficientes= calcularMinimosCuadradosCoef(tamanyo ,n);
  std::vector< std::vector< double> > matrizDeTerminosIndependientes= calcularMinimosCuadradosTerminosInd(tamanyo,tiempo,n);


  std::vector< std::vector< double> > soluciones(n, std::vector<double>(1,0));


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
        aux+=(pow(v[i]-medias,2));

    aux=aux/v.size();

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









std::vector < std::vector< double> > calcularMinimosCuadradosCoef(const std::vector<double> &tamanyo,int n){
   std::vector< std::vector< double> > minimosCuadrados(n, std::vector<double>(n,0));



   for(double i=0;i<n;i++){
      for(double j=0;j<n;j++){
          minimosCuadrados[i][j]=minimosCuadrados[j][i]=sumaVector(tamanyo,j+i);
      }
   }


   return minimosCuadrados;
}

void TiempoAlgoritmos(long long int i){

 long long int mil=0,seg=0,min=0,hor=0,dia=0,anyo=0;
 if(i/1000>=1){
   mil=i/1000;
   i=i%1000;
 }
 if(mil/1000>=1){
   seg=mil/1000;
   mil=mil%1000;
 }
 if(seg/60>=1){
   min=seg/60;
   seg=seg%60;
 }
 if(min/60>=1){
   hor=min/60;
   min=min%60;
 }
 if(hor/24>=1){
   dia=hor/24;
   hor=hor%24;
 }
 if(dia/365>=1){
   anyo=dia/365;
   dia=dia%365;
 }
 std::cout<<anyo<<" años, "<<dia<<" dias, "<<hor<<" horas, "<<min<<" minutos, "<<seg<<" segundos, "<<mil<<"milisegundos "<<i<<" microsegundos\n";

  
}





double sumaVector(const std::vector<double> &vector,double exponente){
     double aux=0;
      for(unsigned int i=0;i<vector.size();i++) aux+=pow(vector[i],exponente);
     return aux;
}



double calcularValorAprox(double valorAprox,const std::vector < std::vector <double> > &soluciones,int n){
    if(valorAprox>0){
         double valor=0;
         for(int i=0;i<n;i++){
           valor+=soluciones[i][0]*pow(valorAprox,i);
         }
	// valor=0 + 1*n +2*n²
        return valor;  
     }
    else return -1;
}
