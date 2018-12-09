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

bool getSolCambio(const std::vector<std::vector <int> > &monedasCamb,const SistemaMonetario &sist,std::vector<int> &sol);

void CambioTiempo();

void MochilaTiempo();

void generarAleatoriamente(std::vector<Material> &mat,int i,int &tamMochila);

std::vector<Moneda> getSistemaMonetario(SistemaMonetario sist);
#endif
