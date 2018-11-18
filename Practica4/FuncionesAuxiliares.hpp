#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include <stack>
#include "Grafo.hpp"
int menu();

void ViajanteDeComercio();

void Viajante(Grafo &grafo,Grafo &solucion);

Grafo unirConjuntos( Grafo &a, Grafo &b,std::string i,std::string j,int peso);

void Cambio();


#endif
