#ifndef MINIMOS_CUADRADOS_HPP
#define MINIMOS_CUADRADOS_HPP

std::vector< std::vector< double> > calcularMinimosCuadrados(const std::vector<double> &tamanyo,const std::vector<double> &tiempo,int n);
std::vector< std::vector< double> > calcularMinimosCuadradosCoef(const std::vector<double> &tamanyo,int n);
std::vector< std::vector< double> > calcularMinimosCuadradosTerminosInd(const std::vector<double> &tamanyo,const std::vector<double> &tiempo,int n);
double sumaVector(const std::vector<double> &vector,double exponente);
double sumatorioMultValores(const std::vector<double> &tamanyo,const std::vector<double> &tiempo,double n);
double determinacion(const std::vector<double> &aprox,const std::vector<double> &tiempo);
double covarianza(const std::vector<double> &v1,const std::vector<double> &v2);
double desviacionTipica(const std::vector<double> &v);
double media(const std::vector<double> &v);
double varianza(const std::vector<double> &v);
double calcularValorAprox(double valorAprox,const std::vector < std::vector <double> > &soluciones,int n);

#endif
