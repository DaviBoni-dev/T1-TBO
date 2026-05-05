#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "UF.h"

struct uf {
    int *id;
    int *sz;
    int count;
} ;


UF *UF_init(int N) {
    UF *my_uf = (UF*) malloc (sizeof(UF)); 
    my_uf->count = N;
    my_uf->id = (int *) malloc (N * sizeof(int));
    for (int i = 0; i < N; i++) {
        my_uf->id[i] = i;
    } 
    my_uf->sz = (int *) malloc (N * sizeof(int));
    for (int i = 0; i < N; i++) {
        my_uf->sz[i] = 1;
    }
    
    return my_uf;
}

int fcount(UF *uf){
    return uf->count;
}

int UF_find(UF *uf, int i) {
    while (i != uf->id[i]){   
        uf->id[i] = uf->id[uf->id[i]];
        i = uf->id[i];    
    }
        
    return i; 
}

int connected(UF *uf, int p, int q){
    return (UF_find(uf, p) == UF_find(uf, q));
}

void UF_destroy(UF *uf){
    
    if(uf != NULL){
        free(uf->id);
        free(uf->sz);
        free(uf);
    }

}

void UF_union(UF *uf, int p, int q) {
    int i = UF_find(uf, p); 
    int j = UF_find(uf, q); 
    if(i == j)
        return;
    
    if(uf->sz[i] < uf->sz[j]){
        uf->id[i] = j;
        uf->sz[j] += uf->sz[i];
    }
    else{
        uf->id[j] = i;
        uf->sz[i] += uf->sz[j];
    }
    uf->count--;
}

void UF_print(UF *uf){
    for(int i = 0; i < uf->count; i++){
        printf("%d\n", uf->id[i]);
    }
}
