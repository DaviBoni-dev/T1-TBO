#include "quickSort.h"

void troca(Aresta *a, Aresta *b){
    Aresta *temp = a;
    a = b;
    b = temp;
}

int menor(Aresta *a, Aresta *b){
    return getPesoAresta(a) < getPesoAresta(b);
}

int particiona(Aresta **arestas, int inicio, int fim){
    int i = inicio;
    int j = fim + 1;
    Aresta *v = arestas[fim];
    while(1){
        while(menor(arestas[i++], v)){
            if(i == fim){
                break;
            }
        }
        
        while(menor(v, arestas[--j])){
            if(j == inicio){
                break;
            }
        }

        if(i >= j){
            break;
        }
        troca(arestas[i], arestas[j]);
            
    }

    troca(arestas[inicio], arestas[fim]);
    return j;

}

void quickSort(Aresta **arestas, int lo, int hi){
    if(hi <= lo){
        return;
    }

    int j = particiona(arestas, lo, hi);
    quickSort(arestas, lo, j-1);
    quickSort(arestas, j + 1, hi);
}