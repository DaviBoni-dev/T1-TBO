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

#endif /* F22BC646_11F2_4685_87D2_EF516C1EEE02 */
