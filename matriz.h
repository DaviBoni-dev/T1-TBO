#ifndef MATRIZ_H
#define MATRIZ_H

#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Cria uma matriz de floats e aloca memória para ela
 * 
 * @param n O tamanho da matriz
 * @return float** - Ponteiro para a matriz criada
 */
float **criaMatriz(int n);

/**
 * @brief Imprime os dados de uma matriz
 * 
 * @param m A matriz a ser impressa
 * @param n O tamanho da matriz
 */
void imprimeMatriz(float **m, int n);

/**
 * @brief Preenche uma matriz com as distâncias euclidianas entre os pontos
 * 
 * @param m A matriz a ser preenchida
 * @param n O tamanho da matriz
 * @param pontos O vetor de pontos
 */
void preencheMatrizComDistancias(float **m, int n, Ponto **pontos);

/**
 * @brief Libera a memória alocada para uma matriz
 * 
 * @param m A matriz a ser liberada
 * @param n O tamanho da matriz
 */
void liberaMatriz(float **m, int n);


#endif /* MATRIZ_H */
