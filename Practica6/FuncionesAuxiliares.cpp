#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include "SistemaMonetario.hpp"
#include "Moneda.hpp"
#include "Mochila.hpp"
#include "Material.hpp"
#include "MinimosCuadrados.hpp"
#include "Tiempo.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;
int menu(){

	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Realizar el problema de la mochila";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Realizar el problema del cambio";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[3] Analisis temporal del problema de la mochila";
	//////////////////////////////////////////////////////////////////////////////

	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}

