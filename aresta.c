#include "aresta.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

 struct aresta{
    int origem;
    int destino;
    float peso;
};


int comparaAresta(const void* a, const void *b){
    Aresta *a1 = *(Aresta**) a;
    Aresta *b1 = *(Aresta**) b;

    if(a1->peso < b1->peso) return -1;
    else if(a1->peso > b1->peso) return 1;
    return 0;
}

Aresta **criaVetorArestas(int n){
    Aresta **arestas = (Aresta **) malloc (n * sizeof(Aresta*));

    for(int i = 0; i < n; i++){
        arestas[i] = (Aresta *) malloc (sizeof(Aresta));
    }

    return arestas;
}

void preencheVetorComDistancias(Aresta **arestas, float **matriz, int contador){
    int f = 0;
    for(int i = 0; i < contador; i++){
        for(int j= i + 1; j < contador; j++){
            arestas[f]->origem = i;
            arestas[f]->destino = j;
            arestas[f]->peso = matriz[i][j];
            f++;
        }
    }
}

void ordenaArestas(Aresta **arestas, int total){
    qsort(arestas, total, sizeof(Aresta*), comparaAresta);
}

int getOrigemAresta(Aresta *a){
    return a->origem;
}

int getDestinoAresta(Aresta *a){
    return a->destino;
}