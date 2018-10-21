#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "combinatorioIterativo.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'combinatorioIterativo.txt' using 1:2 t "Tiempo real" w l,'combinatorioIterativo.txt' using 1:3 t "Tiempo estimado" w l
_end_
