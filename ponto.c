#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ponto.h"

struct ponto  {
    double *valores;
    int tamValoresPreenchidos;
    int tamValoresTotal;
    int m;
    char *idUnico;
    int tamId;
};

Ponto *criaPonto(Ponto *ponto){
    
    if(ponto == NULL){
        fprintf(stderr, "Erro ao alocar memoria para ponto\n");
        exit(EXIT_FAILURE);
    }
    
    ponto->valores = (double *) malloc (10 * sizeof(double));
    ponto->m = 0;
    ponto->tamValoresTotal = 10;
    ponto->tamValoresPreenchidos = 0;
    ponto->idUnico = NULL;

}

Ponto *getPonto(Ponto *p, int i){
    return &p[i];
}

Ponto *criaVetorPontos(int n){
     Ponto *pontos = (Ponto *) malloc (n * sizeof(Ponto ));

    if(pontos == NULL){
        fprintf(stderr, "Erro ao alocar memoria para vetor de pontos\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < n; i++){
        pontos[i].valores = (double *) malloc(10 * sizeof(double));
        pontos[i].m = 0;
        pontos[i].tamValoresTotal = 10;
        pontos[i].tamValoresPreenchidos = 0;
        pontos[i].idUnico = NULL;
    }

    return pontos;
}

void adicionaIdPonto(Ponto *p, char *id){

    p->idUnico = strdup(id);
    p->tamId = strlen(id) + 1;
}

char *getIdUnico(Ponto *p){
    return p->idUnico;
}

Ponto *realocaVetorPontos(Ponto *p, int n){
    Ponto *temp = (Ponto *) realloc (p, n * (sizeof(Ponto)));

    if(temp == NULL){
        fprintf(stderr, "Erro ao realocar memoria para vetor de pontos\n");
        exit(EXIT_FAILURE);
    }

    return temp;

}

double calculaDistanciaEuclidiana(Ponto *p1, Ponto *p2){
    
    double total = 0;
    for(int i = 0; i < p1->m; i++){
        double diferenca = p1->valores[i] - p2->valores[i];
        total += diferenca * diferenca;
    }

    return total; //Como só queremos ordenar, não importa a raiz ou o valor quadratico
}


void adicionaValorPonto(Ponto *p, double valor){

    if(p->tamValoresPreenchidos == p->tamValoresTotal){
        double *temp = (double *) realloc (p->valores, (2 * p->tamValoresPreenchidos) * sizeof(double));

        if(temp != NULL){
            p->tamValoresTotal *= 2;
            p->valores = temp;
        } else {          
            fprintf(stderr, "Erro ao realocar memoria para valores do ponto\n");
            exit(EXIT_FAILURE);
        }
    }

    p->valores[p->tamValoresPreenchidos] = valor;
    p->tamValoresPreenchidos++;
    p->m++;
}



void liberaPonto(Ponto *p){
    if(p != NULL){
        if(p->idUnico != NULL)
        free(p->idUnico);
        if(p->valores != NULL)
        free(p->valores);


        free(p);
    }
}

void liberaVetorPontos(Ponto *pontos, int n){

    for(int i = 0; i < n; i++){
        free(pontos[i].idUnico);
        free(pontos[i].valores);
    }

    free(pontos);
}

