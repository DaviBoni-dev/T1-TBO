#ifndef F22BC646_11F2_4685_87D2_EF516C1EEE02
#define F22BC646_11F2_4685_87D2_EF516C1EEE02

#include "aresta.h"
#include "ponto.h"
#include "grupo.h"

typedef struct noarvore NoArvore;

NoArvore **criaVetorArvores(int n);

void addArestaNaArvore(Aresta *a, NoArvore **arvore);

void imprimir_arvore_debug(NoArvore** arvore, int n_pontos, Ponto** vetor_de_pontos);
void percorreArvore(NoArvore **arvore, int n_pontos, Ponto **pontos, Grupo **grupos, int *contador_grupo);
void DFS(int id_atual, NoArvore** arvore, int* visitado, int* tamanho_grupo, Grupo **grupos, int contador_grupo, Ponto **pontos);
void liberaVetorArvores(NoArvore **arvore, int n);
#endif /* F22BC646_11F2_4685_87D2_EF516C1EEE02 */
