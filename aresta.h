#ifndef ARESTA_H
#define ARESTA_H

typedef struct aresta Aresta;

#include <stdio.h>
#include <stdlib.h>

int comparaAresta(const void* a, const void *b);
Aresta **criaVetorArestas(int n);
void preencheVetorComDistancias(Aresta **arestas, float **matriz, int contador);
void ordenaArestas(Aresta **arestas, int total);
int getOrigemAresta(Aresta *a);
int getDestinoAresta(Aresta *a);
float getPesoAresta(Aresta *a);
void liberaAresta(Aresta *a);

void liberaVetorArestas(Aresta **a, int n);

#endif /* ARESTA_H */
