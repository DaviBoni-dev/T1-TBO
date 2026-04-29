#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "ponto.c"
//#include "UF.c"
#include "arvore.h"
#include <math.h>


/////UF


typedef struct uf {
    int *id;
    int *sz;
    int count;
    int size;
} UF;



UF *UF_init(int N) {
    UF *my_uf = (UF*) malloc (sizeof(UF)); 
    my_uf->count = N;
    my_uf->size = N;
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
    while (i != uf->id[i]) i = uf->id[i];
    return i; 
}

int connected(UF *uf, int p, int q){
    return (UF_find(uf, p) == UF_find(uf, q));
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
    for(int i = 0; i < uf->size; i++){
        printf("%d\n", uf->id[i]);
    }
}

////////////ponto


typedef struct ponto  {
    float *valores;
    int tamValoresPreenchidos;
    int tamValoresTotal;
    int m;
    char *idUnico;
    int tamId;
} Ponto;

Ponto *criaPonto(){
    Ponto *ponto = (Ponto *) malloc (sizeof(Ponto));
    ponto->valores = (float *) malloc (10 * sizeof(float));
    ponto->m = 0;
    ponto->tamValoresTotal = 10;
    ponto->tamValoresPreenchidos = 0;
    return ponto;
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

void liberaPonto(Ponto *p){
    if(p->idUnico != NULL)
    free(p->idUnico);
    if(p->valores != NULL)
    free(p->valores);

    free(p);
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

typedef struct {
    int origem;
    int destino;
    float peso;
} Aresta;

int comparaAresta(const void* a, const void *b){
    Aresta *a1 = (Aresta*) a;
    Aresta *b1 = (Aresta*) b;

    if(a1->peso < b1->peso) return -1;
    else if(a1->peso > b1->peso) return 1;
    return 0;
}

float **criaMatriz(int n){
    float **matrizDistancias = (float **) malloc (n * sizeof(float *));
    for(int i = 0; i < n; i++){
        matrizDistancias[i] = (float *) malloc (n * sizeof(float));
    }
    return matrizDistancias;
}

void imprimeMatriz(float **m, int n){
        for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            printf("%.2f ", m[i][j]);
        }

        printf("\n");
    }
}

void preencheMatrizComDistancias(float **m, int n, Ponto **pontos){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                m[i][j] = calculaDistanciaEuclidiana(pontos[i], pontos[j]);
            }
    }

}

void liberaMatriz(float **m, int n){
    for(int i = 0; i < n; i++){
        free(m[i]);
    }

    free(m);
}


int main(int argc, char *argv[]){

    FILE *entrada = fopen("entrada.txt", "r");

    Ponto **pontos = criaVetorPontos();

    
    char *linha = NULL;
    size_t tam = 0;
    int contador = 0;
    
    while(getline(&linha, &tam, entrada) != -1){
        
        char *token = strtok(linha, ",");
        adicionaIdPonto(pontos[contador], token);
        
        while(token != NULL){
            //printf("%s\n", token);
            token = strtok(NULL, ",");
            if(token != NULL){
                float valor = atof(token);
                adicionaValorPonto(pontos[contador], valor);
                
            }
        }
        
        contador++;
    }
    
    float **matrizDistancias = criaMatriz(contador);
    preencheMatrizComDistancias(matrizDistancias, contador, pontos);
    //imprimeMatriz(matrizDistancias, contador);


    int totalArestas = (contador * (contador - 1)) / 2;

    Aresta *arestas = (Aresta *) malloc (totalArestas * sizeof(Aresta));

    int f = 0;
    for(int i = 0; i < contador; i++){
        for(int j= i + 1; j < contador; j++){
            arestas[f].origem = i;
            arestas[f].destino = j;
            arestas[f].peso = matrizDistancias[i][j];
            f++;
        }
    }

    qsort(arestas, totalArestas, sizeof(Aresta), comparaAresta);

   // for(int i = 0; i < totalArestas; i++){
     //   printf("%.2f/ ", arestas[i].peso);
    //}

    UF *uf = UF_init(contador);

    Forest *forest = criaForest(contador);

    for(int i = 0; i < contador; i++){
        Arv *a = arv_cria(i, NULL, NULL, contador);
        adicionaRaizForest(forest,  a, i);
    }

    forest_imprime(forest);

     for(int i = 0; i < totalArestas; i++){
        Aresta atual = arestas[i];
        int src = atual.origem;
        int dst = atual.destino;

        if(UF_find(uf, atual.origem) != UF_find(uf, atual.destino)){
            arv_adiciona(src, dst, forest);
            UF_union(uf, atual.origem, atual.destino);
        }
    }

    printf("\n\n\n");
    forest_imprime(forest);
    printf("\n\n\n");


    UF_print(uf);

    liberaMatriz(matrizDistancias, contador);

    free(linha);
    fclose(entrada);

    liberaVetorPontos(pontos, contador);

    return 0;

}


