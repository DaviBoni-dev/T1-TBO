#ifndef ARESTA_H
#define ARESTA_H

typedef struct aresta Aresta;

#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

/**
 * @brief Cria um vetor de arestas de tamanho n
 * 
 * @param n O número de arestas a ser criado
 * @return Aresta* - Ponteiro para o vetor de arestas criado
 */
Aresta *criaPiscinaAresta(int n);

/**
 * @brief Cria um vetor de arestas
 * 
 * @param n O número de arestas a ser criado
 * @return Aresta** - Ponteiro para o vetor de arestas criado
 */
Aresta **criaVetorArestas(int n, Aresta *pool);

int comparaArestaSimples(const void *a, const void *b);

void ordenaArestasDireta(Aresta *arestas, int total);

Aresta* getAresta(Aresta *arestas, int i);

/**
 * @brief Ordena o vetor de arestas com base em seu peso
 * 
 * @param arestas O vetor de arestas a ser ordenado
 * @param total O número total de arestas no vetor
 */
void ordenaArestas(Aresta **arestas, int total);

void preencheVetorComDistanciasDireto(Aresta *pool, Ponto **pontos, int contador);

/**
 * @brief Compara duas arestas com base em seu peso
 * 
 * @param a Uma aresta a ser comparada com cast para void*
 * @param b Uma aresta a ser comparada com cast para void*
 * @return int - Valor negativo se a primeira aresta for menor, zero se forem iguais, positivo se a primeira aresta for maior
 */
int comparaAresta(const void* a, const void *b);

/**
 * @brief Preenche o vetor de arestas com as distâncias da matriz
 * 
 * @param arestas O vetor de arestas a ser preenchido
 * @param pontos O vetor de pontos a serem calculados as distâncias
 * @param contador O número de arestas a ser preenchido
 */
void preencheVetorComDistancias(Aresta **arestas, Ponto **pontos, int contador);


/**
 * @brief Obtém o vértice de origem de uma aresta
 * 
 * @param a Uma aresta
 * @return int - O vértice de origem da aresta
 */
int getOrigemAresta(Aresta *a);

/**
 * @brief Obtém o vértice de destino de uma aresta
 * 
 * @param a Uma aresta
 * @return int - O vértice de destino da aresta
 */
int getDestinoAresta(Aresta *a);

/**
 * @brief Obtém o peso de uma aresta
 * 
 * @param a Uma aresta
 * @return double - O peso da aresta
 */
double getPesoAresta(Aresta *a);

/**
 * @brief Libera a memória alocada para uma aresta
 * 
 * @param a Uma aresta
 */
void liberaAresta(Aresta *a);

/**
 * @brief Libera a memória alocada para um vetor de arestas
 * 
 * @param a Um vetor de arestas
 * @param n O número de arestas no vetor
 */
void liberaVetorArestas(Aresta **a, Aresta *piscina);

#endif /* ARESTA_H */
