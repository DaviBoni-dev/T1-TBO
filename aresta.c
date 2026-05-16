#include "aresta.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

 struct aresta{
    double peso;
    int origem;
    int destino;
};


Aresta *criaVetorAresta(int n){
    Aresta *arestas = (Aresta *) malloc (n * sizeof(Aresta));

    if(arestas == NULL){
        fprintf(stderr, "Erro ao alocar memoria para piscina de arestas\n");
        exit(EXIT_FAILURE);
    }
    
    return arestas;
}

void ordenaArestas(Aresta *arestas, int total){
    qsort(arestas, total, sizeof(Aresta), comparaAresta);
}

int comparaAresta(const void *a, const void *b){
    Aresta *a1 = (Aresta *) a;
    Aresta *b1 = (Aresta *) b;
    
    if(a1->peso < b1->peso) return -1;
    if(a1->peso > b1->peso) return  1;
    return 0;
}

Aresta *getAresta(Aresta *arestas, int i){
    return &arestas[i];
}

void preencheVetorComDistancias(Aresta *pool, Ponto *pontos, int contador){
    int f = 0;
    for(int i = 0; i < contador; i++){
        for(int j = i + 1; j < contador; j++){
            pool[f].origem = i;
            pool[f].destino = j;
            pool[f].peso = calculaDistanciaEuclidiana(getPonto(pontos, i), getPonto(pontos, j));
            f++;
        }
    }
}

int getOrigemAresta(Aresta *a){
    return a->origem;
}

int getDestinoAresta(Aresta *a){
    return a->destino;
}

double getPesoAresta(Aresta *a){
    return a->peso;
}

void liberaAresta(Aresta *a){
    if(a != NULL)
        free(a);
}



