#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include "SistemaMonetario.hpp"
#include "Material.hpp"
#include "Mochila.hpp"

int menu();

void AlgMochila();

void mochAlgDin(const std::vector<Material> &m,std::vector<std::vector <int> > &solucion,int n);

void getSolucionMochila(const std::vector<Material> &m,const std::vector<std::vector <int> > &solucion,Mochila &moc);

void Cambio();

int min(int i,int j);

void cambAlgDinam(const SistemaMonetario &sist,int n, std::vector<std::vector <int> > &vectorCamb);

#endif
