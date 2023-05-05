#ifndef kalkulasi_h
#define kalkulasi_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "tree.h"



double kalkulasi(address P);
double proses_perhitungan_trigonometri(double angka, char operator[]);
double proses_perhitungan_logaritma(double angka1, double angka2, char opera[]);
double proses_perhitungan_single_operand_long_operator(double angka, char opera[]);
double proses_perhitungan_single_operand_single_operator(double angka, char opera);
#endif