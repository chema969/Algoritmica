#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include <stack>
int menu();


long double combinatorioRecursivo(long double n, long double k);


long double combinatorioIterativo(long double n,long double k);


void numerosCombinatorios();


void opcionesHanoi();


void numerosCombinatoriosRecursivosSinTabla();


void numerosCombinatoriosRecursivosConTabla();


void numerosCombinatoriosIterativos();


long double combinatorioRecursivoConTabla(long double n, long double k,std::vector < std::vector< long double> > &tabla);


void hanoi(std::vector<std::vector <int>  > &varillas,int nDiscos,int i,int j,int &movimientos);


void realizarHanoi();


void realizarHanoiImprimiendo();


void hanoiSinImprimir(std::vector<std::stack <int>  > &varillas,int nDiscos,int i,int j,int &movimientos);


void imprimir(const std::vector<std::vector <int>  > &varillas,int movimientos);

#endif
