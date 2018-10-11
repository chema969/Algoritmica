#ifndef MINIMOS_CUADRADOS_HPP
#define MINIMOS_CUADRADOS_HPP

std::vector< std::vector< double> > calcularMinimosCuadrados(std::vector<double> tamanyo,int n);
std::vector< std::vector< double> > calcularMinimosCuadradosTerminosInd(std::vector<double> tamanyo,std::vector<double>tiempo,int n);
double sumaVector(std::vector<double> vector,double exponente);
double sumatorioMultValores(std::vector<double> tiempo,std::vector<double> tamanyo,double n);
double determinacion(std::vector<double> aprox,std::vector<double> tiempo);
double covarianza(std::vector<double> v1,std::vector<double> v2);
double desviacionTipica(std::vector<double> v);
double media(std::vector<double> v);
double varianza(std::vector<double> v);
double calcularValorAprox(int valorAprox,std::vector < std::vector <double> > soluciones);

#endif
