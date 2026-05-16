#include "aresta.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

 struct aresta{
    double peso;
    int origem;
    int destino;
};


Aresta *criaPiscinaAresta(int n){
    Aresta *pool = (Aresta *) malloc (n * sizeof(Aresta));

    if(pool == NULL){
        fprintf(stderr, "Erro ao alocar memoria para piscina de arestas\n");
        exit(EXIT_FAILURE);
    }
    
    return pool;
}

Aresta **criaVetorArestas(int n, Aresta *pool){
    Aresta **arestas = (Aresta **) malloc (n * sizeof(Aresta*));
    
    if(arestas == NULL){
        fprintf(stderr, "Erro ao alocar memoria para vetor de arestas\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < n; i++){
        arestas[i] = &pool[i];
    }

    return arestas;
}

void ordenaArestas(Aresta **arestas, int total){
    qsort(arestas, total, sizeof(Aresta*), comparaAresta);
}

void ordenaArestasDireta(Aresta *arestas, int total){
    qsort(arestas, total, sizeof(Aresta), comparaArestaSimples);
}

int comparaAresta(const void* a, const void *b){
    Aresta *a1 = *(Aresta**) a;
    Aresta *b1 = *(Aresta**) b;

    if(a1->peso < b1->peso) return -1;
    else if(a1->peso > b1->peso) return 1;
    return 0;
}

int comparaArestaSimples(const void *a, const void *b){
    Aresta *a1 = (Aresta *) a;
    Aresta *b1 = (Aresta *) b;
    
    if(a1->peso < b1->peso) return -1;
    if(a1->peso > b1->peso) return  1;
    return 0;
}

Aresta *getAresta(Aresta *arestas, int i){
    return &arestas[i];
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

void preencheVetorComDistanciasDireto(Aresta *pool, Ponto **pontos, int contador){
    int f = 0;
    for(int i = 0; i < contador; i++){
        for(int j = i + 1; j < contador; j++){
            pool[f].origem = i;
            pool[f].destino = j;
            pool[f].peso = calculaDistanciaEuclidiana(pontos[i], pontos[j]);
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

void liberaVetorArestas(Aresta **a, Aresta *piscina){
    free(piscina);
    free(a);
}


