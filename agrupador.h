#ifndef AGRUPADOR_H
#define AGRUPADOR_H

#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "aresta.h"
#include "UF.h"
#include "grupo.h"
#include "MST.h"
#include "agrupador.h"

#define TAM_MAX_INICIAL_VETOR 10

/**
 * @brief Estrutura que representa e contém todas as informações necessárias para realizar o agrupamento dos pontos, incluindo os pontos, as arestas, a estrutura Union-Find, a árvore gerada e os grupos formados.
 * 
 */
typedef struct agrupador Agrupador;

/**
 * @brief Cria um novo agrupador com k grupos.
 * 
 * @param k Número de grupos desejado.
 * @return Agrupador* Ponteiro para o agrupador criado.
 */
Agrupador *criaAgrupador(int k);

/**
 * @brief Lê os pontos de um arquivo e os adiciona ao agrupador.
 * 
 * @param a Ponteiro para o agrupador.
 * @param entrada Ponteiro para o arquivo de entrada.
 */
void lePontos(Agrupador *a, FILE *entrada);

/**
 * @brief Preenche e ordena as arestas do agrupador.
 * 
 * @param a Ponteiro para o agrupador.
 */
void preencheOrdenaArestas(Agrupador *a);

/**
 * @brief Cria a árvore geradora mínima (MST) do agrupador com k grupos.
 * 
 * @param a Ponteiro para o agrupador.
 */
void criaMST(Agrupador *a);

/**
 * @brief Cria e ordena os grupos do agrupador.
 * 
 * @param a Ponteiro para o agrupador
 */
void criaOrdenaGrupos(Agrupador *a);

/**
 * @brief Imprime os grupos formados em um arquivo.
 * 
 * @param a Ponteiro para o agrupador.
 * @param saida Ponteiro para o arquivo de saída.
 */
void imprimeGruposArquivo(Agrupador *a, FILE *saida);

/**
 * @brief Libera a memória alocada para o agrupador.
 * 
 * @param a Ponteiro para o agrupador.
 */
void liberaAgrupador(Agrupador *a);

#endif 
