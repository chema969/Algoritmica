#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "Nreinas.eps"
set key right bottom
set xlabel "Muestras"
set ylabel "Tiempo"
plot 'NReinasBacktracking.txt' using 1:2 t "Tiempo real" w l,'NReinasBacktracking.txt' using 1:3 t "Tiempo estimado" w l
_end_
