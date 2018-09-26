CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(practica1_ed)
set (CMAKE_CXX_FLAGS "-lrt -g")
add_executable(Principal Principal.cpp Tiempo.cpp Vector.cpp FuncionesAuxiliares.cpp sistemaEcuaciones.cpp)
 
