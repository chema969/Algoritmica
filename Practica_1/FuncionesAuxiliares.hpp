#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP
#include <vector>

int menu();
void metodoSeleccion();
void metodoMonticulos();
bool evaluarDatos(int inicio,int fin,int subida,int repeticiones);
double sumaVector(std::vector<double> vector,double exponente);
std::vector< std::vector< double> > calcularMinimosCuadrados(std::vector<double> tamanyo,int n);
std::vector< std::vector< double> > calcularMinimosCuadradosTerminosInd(std::vector<double> tamanyo,std::vector<double>tiempo,int n);
double z(double n);
double sumatorioMultValores(std::vector<double> tiempo,std::vector<double> tamanyo,double n);




#endif
