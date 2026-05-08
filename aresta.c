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

Aresta *criaPiscinaAresta(int n){
    Aresta *pool = (Aresta *) malloc (n * sizeof(Aresta));

    return pool;
}

Aresta **criaVetorArestas(int n, Aresta *pool){
    Aresta **arestas = (Aresta **) malloc (n * sizeof(Aresta*));
    
    for(int i = 0; i < n; i++){
        arestas[i] = &pool[i];
    }

    return arestas;
}

float getPesoAresta(Aresta *a){
    return a->peso;
}

void liberaAresta(Aresta *a){
    if(a != NULL)
        free(a);
}

void liberaVetorArestas(Aresta **a, int n){
    for(int i = 0; i < n; i++){
        liberaAresta(a[i]);
    }

    free(a);
}

void preencheVetorComDistancias(Aresta **arestas, Ponto **pontos, int contador){
    int f = 0;
    for(int i = 0; i < contador; i++){
        for(int j= i + 1; j < contador; j++){
            arestas[f]->origem = i;
            arestas[f]->destino = j;
            arestas[f]->peso = calculaDistanciaEuclidiana(pontos[i], pontos[j]);
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