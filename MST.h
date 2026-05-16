#ifndef MST_H
#define MST_H

#include "aresta.h"
#include "ponto.h"
#include "grupo.h"


/** @brief Estrutura que representa um nó na árvore.
 */
typedef struct noarvore NoArvore;

/** @brief Cria um vetor de nós de árvore e aloca memória para ele.
 * @param n Número de nós na árvore.
 * @return NoArvore** - Ponteiro para o vetor de nós de árvore criado.
 */
NoArvore **criaVetorArvores(int n, int max_nos);

/**
 * @brief Cria um nó de árvore e aloca memória para ele.
 * @param n Número de nós na árvore.
 * @return NoArvore* - Ponteiro para o nó de árvore criado.
 */
NoArvore *criaNoArvore(int n);

/** @brief Adiciona uma aresta à árvore usando uma piscina de nós para otimizar a alocação de memória.
 * @param a Ponteiro para a aresta a ser adicionada.
 * @param arvore Ponteiro para o vetor de nós de árvore.
 * @param pool Ponteiro para a piscina de nós.
 * @param contador_pool Ponteiro para o contador da piscina de nós.
 * @param max_nos O número máximo de nós na piscina.
 */
void addArestaNaArvoreComPiscina(Aresta *a, NoArvore **arvore, NoArvore *pool, int *contador_pool, int max_nos);



/** @brief Percorre a árvore e identifica os grupos.
 * @param arvore Ponteiro para o vetor de nós de árvore.
 * @param n_pontos Número de pontos na árvore.
 * @param pontos Ponteiro para o vetor de pontos.
 * @param grupos Ponteiro para o vetor de grupos.
 * @param contador_grupo Ponteiro para o contador de grupos.
 */
void percorreArvore(NoArvore **arvore, int n_pontos, Ponto *pontos, Grupo **grupos, int *contador_grupo);

/** @brief Libera a memória alocada para um vetor de nós de árvore.
 * @param arvore Ponteiro para o vetor de nós de árvore.
 * @param n Número de nós na árvore.
 */
void liberaVetorArvores(NoArvore **arvore, NoArvore *piscina);

#endif 
