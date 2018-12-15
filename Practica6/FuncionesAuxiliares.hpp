#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include "NReinas.hpp"
int menu();

void solucionNReinas();

void BacktrackingNreinas(std::vector<NReinas> &soluciones,int n,bool unaSol=false);

bool LasVegasNreinas(NReinas &solucion,int n);

void solucionNReinasLasVegas();

void analisisBacktracking();

long double factorial(double i);

void analisisNReinasLasVegas();

void comparacionNReinas();
#endif
