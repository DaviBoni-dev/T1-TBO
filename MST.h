#ifndef F22BC646_11F2_4685_87D2_EF516C1EEE02
#define F22BC646_11F2_4685_87D2_EF516C1EEE02

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

NoArvore *criaNoArvore(int n);

/** @brief Adiciona uma aresta a uma árvore.
 * @param a Ponteiro para a aresta a ser adicionada.
 * @param arvore Ponteiro para o vetor de nós de árvore.
 */
void addArestaNaArvore(Aresta *a, NoArvore **arvore, int *contador_arvore);

void addArestaNaArvoreComPiscina(Aresta *a, NoArvore **arvore, NoArvore *pool, int *contador_pool);


/** @brief Imprime os dados de uma árvore para depuração.
 * @param arvore Ponteiro para o vetor de nós de árvore.
 * @param n_pontos Número de pontos na árvore.
 * @param vetor_de_pontos Ponteiro para o vetor de pontos.
 */
void imprimir_arvore_debug(NoArvore** arvore, int n_pontos, Ponto** vetor_de_pontos);

/** @brief Percorre a árvore e identifica os grupos.
 * @param arvore Ponteiro para o vetor de nós de árvore.
 * @param n_pontos Número de pontos na árvore.
 * @param pontos Ponteiro para o vetor de pontos.
 * @param grupos Ponteiro para o vetor de grupos.
 * @param contador_grupo Ponteiro para o contador de grupos.
 */
void percorreArvore(NoArvore **arvore, int n_pontos, Ponto **pontos, Grupo **grupos, int *contador_grupo);

/** @brief Realiza uma busca em profundidade na árvore.
 * @param id_atual O ID do nó atual.
 * @param arvore Ponteiro para o vetor de nós de árvore.
 * @param visitado Ponteiro para o vetor de nós visitados.
 * @param tamanho_grupo Ponteiro para o tamanho do grupo.
 * @param grupos Ponteiro para o vetor de grupos.
 * @param contador_grupo O contador de grupos.
 * @param pontos Ponteiro para o vetor de pontos.
 */
void DFS(int id_atual, NoArvore** arvore, int* visitado, int* tamanho_grupo, Grupo **grupos, int contador_grupo, Ponto **pontos);

/** @brief Libera a memória alocada para um vetor de nós de árvore.
 * @param arvore Ponteiro para o vetor de nós de árvore.
 * @param n Número de nós na árvore.
 */
void liberaVetorArvores(NoArvore **arvore, int n);


#endif /* F22BC646_11F2_4685_87D2_EF516C1EEE02 */
