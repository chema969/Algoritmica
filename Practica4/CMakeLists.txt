CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(practica1_ed)
set (CMAKE_CXX_FLAGS "-lrt -g -std=c++11")
add_executable(Principal Principal.cpp Grafo.cpp FuncionesAuxiliares.cpp Lado.cpp)
 
