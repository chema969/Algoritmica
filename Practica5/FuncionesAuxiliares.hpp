#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include "SistemaMonetario.hpp"

int menu();

void Mochila();

void Cambio();

int min(int i,int j);

void cambAlgDinam(const SistemaMonetario &sist,int n, std::vector<std::vector <int> > &vectorCamb);

#endif
