#ifndef DBCE101B_92E8_4162_9EB2_440F3DDC57F5
#define DBCE101B_92E8_4162_9EB2_440F3DDC57F5

#include <stdio.h>
#include "aresta.h"

void troca(Aresta *a, Aresta *b);

int menor(Aresta *a, Aresta *b);

int particiona(Aresta **arestas, int inicio, int fim);

void quickSort(Aresta **arestas, int lo, int hi);


#endif /* DBCE101B_92E8_4162_9EB2_440F3DDC57F5 */
