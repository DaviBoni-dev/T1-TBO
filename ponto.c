#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ponto.h"

struct ponto  {
    float *valores;
    int tamValoresPreenchidos;
    int tamValoresTotal;
    int m;
    char *idUnico;
    int tamId;
};

Ponto *criaPonto(){
    Ponto *ponto = (Ponto *) malloc (sizeof(Ponto));
    ponto->valores = (float *) malloc (10 * sizeof(float));
    ponto->m = 0;
    ponto->tamValoresTotal = 10;
    ponto->tamValoresPreenchidos = 0;
    return ponto;
}

char *getIdUnico(Ponto *p){
    return p->idUnico;
}

void adicionaIdPonto(Ponto *p, char *id){

    p->idUnico = strdup(id);
    p->tamId = strlen(id) + 1;
}
float calculaDistanciaEuclidiana(Ponto *p1, Ponto *p2){
    
    float total = 0;
    for(int i = 0; i < p1->m; i++){
        float diferenca = p1->valores[i] - p2->valores[i];
        total += pow(diferenca, 2);
    }

    return sqrt(total);
}


void adicionaValorPonto(Ponto *p, float valor){

    if(p->tamValoresPreenchidos == p->tamValoresTotal){
        float *temp = (float *) realloc (p->valores, (2 * p->tamValoresPreenchidos) * sizeof(float));

        if(temp != NULL){
            p->tamValoresTotal *= 2;
            p->valores = temp;
        } else {
           
            printf("Erro: Falta de memória ao adicionar valor!\n");
            return;
        }
    }

    p->valores[p->tamValoresPreenchidos] = valor;
    p->tamValoresPreenchidos++;
    p->m++;
}

Ponto **criaVetorPontos(){
     Ponto **pontos = (Ponto **) malloc (10 * sizeof(Ponto *));

    for(int i = 0; i < 10; i++){
        pontos[i] = criaPonto();
    }

    return pontos;
}

Ponto **realocaVetorPontos(Ponto **p, int n){
    Ponto **temp = (Ponto **) realloc (p, n * (sizeof(Ponto*)));

    if(temp != NULL){
        return temp;
    }
    else{
        printf("Não foi possível alocar memória para o número total de pontos\n");
        exit(0);
        return p;
    }

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

void imprimePonto(Ponto *p){
    printf("%s", p->idUnico);
    for(int i = 0; i < p->tamValoresPreenchidos; i++){
        printf(",%.2f", p->valores[0]);
    }

    printf("\n");
}

void imprimeVetorPontos(Ponto **pontos, int n){
    for(int i = 0; i < n; i++){
        imprimePonto(pontos[i]);
    }
}

void liberaVetorPontos(Ponto **pontos, int n){

    for(int i = 0; i < n; i++){
        liberaPonto(pontos[i]);
    }

    free(pontos);
}

