#ifndef MATRIZ_H
#define MATRIZ_H

#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>


float **criaMatriz(int n);


void imprimeMatriz(float **m, int n);

void preencheMatrizComDistancias(float **m, int n, Ponto **pontos);


void liberaMatriz(float **m, int n);


#endif /* MATRIZ_H */
