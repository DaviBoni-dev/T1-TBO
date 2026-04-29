#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

 struct arv {
    int valor;
    int peso;
    Arv **filhos;
    int numFilhos;
 };


struct forest{
    Arv **raizes;
    int num;
    int *pais;

};

Forest *criaForest(int n){
    Forest *f = (Forest *) malloc (sizeof(Forest));
    f->raizes = (Arv **) malloc (n * sizeof(Arv*));
    f->pais = (int *) malloc (n * sizeof(int));
    for(int i = 0; i < n; i++){
        f->raizes[i] = (Arv *) malloc (sizeof(Arv));
        f->pais[i] = 1;
    }
    f->num = n;

    return f;
}

void adicionaRaizForest(Forest *f, Arv *a, int indice){
    f->raizes[indice] = a;
}

//Cria uma arvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//cria uma arvore com a informacao do no raiz c, e com subarvore esquerda e e subarvore direita d
Arv* arv_cria (int c, Arv* e, Arv* d, int maxF){
    Arv* arvore = (Arv *) malloc (sizeof(Arv));
    arvore->valor = c;
    arvore->numFilhos = 0;
    arvore->peso = 0;
    arvore->filhos = (Arv **) malloc(maxF * sizeof(Arv*));
    for(int i = 0; i < maxF; i++){
        arvore->filhos[i] = NULL;
    }
    
    return arvore;
}
/*
void forest_imprime(Forest *f){
    for(int i = 0; i < f->num; i++){
        if(f->raizes[i] != NULL){
            arv_imprime(f->raizes[i]);
        }
    }
}
*/
void forest_imprime(Forest *f) {
    printf("=== Status da Floresta ===\n");
    for (int i = 0; i < f->num; i++) {
        if (f->raizes[i] != NULL && f->pais[i]) {
            printf("\n[Árvore %d]\n", i + 1);
            arv_imprime_visual(f->raizes[i], 0); // Começa no nível 0
        }
    }
    printf("\n==========================\n");
}

void arv_imprime (Arv* a){
    if(a == NULL){
        return;
    }
    printf(" < %d", a->valor);
    if(a->numFilhos == 0){
        printf(" <>");
    }

    for(int i = 0; i < a->numFilhos; i++){
        arv_imprime(a->filhos[i]);
    }


    printf(" >\n");
}

// Função auxiliar que carrega o nível atual da recursão
void arv_imprime_visual(Arv* a, int nivel) {
    if (a == NULL) {
        return;
    }

    // 1. Imprime os espaços correspondentes à profundidade (nível)
    for (int i = 0; i < nivel; i++) {
        printf("    "); // 4 espaços por nível para dar um bom distanciamento
    }
    
    // 2. Imprime um "galho" para os filhos (a raiz não precisa)
    if (nivel > 0) {
        printf("|-- ");
    }

    // 3. Imprime o valor do nó e quebra a linha
    printf("%c\n", a->valor + 65);

    // 4. Chama a recursão para os filhos aumentando o nível
    for (int i = 0; i < a->numFilhos; i++) {
        arv_imprime_visual(a->filhos[i], nivel + 1);
    }
}

void arv_adiciona(int src, int dst, Forest *f){
    Arv *arv_dest = f->raizes[dst];
    f->raizes[dst]->filhos[f->raizes[dst]->numFilhos] = f->raizes[src];
    f->raizes[dst]->numFilhos++;
    f->pais[src] = 0;
}

/*
//libera o espaco de memoria ocupado pela arvore a
Arv* arv_libera (Arv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esquerda);
        arv_libera(a->direita);
        free(a);
    }

    return NULL;
}

Aluno *arv_get_aluno (Arv* a){
    if(arv_vazia(a)){
        return NULL;
    }
    return a->aluno;
}

//retorna true se a arvore estiver vazia e false caso contrario
int arv_vazia (Arv* a){
    return a == NULL;
}

//indica a ocorrencia (1) ou nao (0) do aluno (pela chave de busca mat)
int arv_pertence (Arv* a, int mat){
    if(arv_vazia(a))
    return 0;
    else
    return (get_matricula(a->aluno) == mat) ||
        arv_pertence(a->esquerda, mat) || arv_pertence(a->direita, mat);
       
   
}

//imprime as informacoes dos nos da arvore

//retorna a mae/pai de um dado no que contem o aluno com a matricula mat
Arv* arv_pai(Arv* a, int mat) {

    if (a == NULL) {
        return NULL;
    }


    if (a->esquerda != NULL && get_matricula(a->esquerda->aluno) == mat) {
        return a; 
    }


    if (a->direita != NULL && get_matricula(a->direita->aluno) == mat) {
        return a; 
    }

    Arv* pai_na_esquerda = arv_pai(a->esquerda, mat);
    if (pai_na_esquerda != NULL) {
        return pai_na_esquerda;
    }

  
    Arv* pai_na_direita = arv_pai(a->direita, mat);
    if (pai_na_direita != NULL) {
        return pai_na_direita;
    }

 
    return NULL;
}  


//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a){
 
    if(a == NULL){
        return 0;
    }
    else if(a->direita == NULL && a->esquerda == NULL){
        return 1;
    }
    else{
      return folhas(a->esquerda) +  folhas(a->direita);
}


}

//retorna o numero de ocorrencias de um dado aluno na arvore
int ocorrencias (Arv* a, int mat){
    if (arv_vazia(a)) {
        return 0;
    }

    int count = 0;

    if (get_matricula(a->aluno) == mat) {
        count = 1;
    }

    count += ocorrencias(a->esquerda, mat);

    count += ocorrencias(a->direita, mat);

    return count;
}

//retorna a altura da arvore a
int altura(Arv* a){
    // Caso base: A altura de uma arvore vazia e -1.
    if (arv_vazia(a)) {
        return -1;
    }

    int alt_esquerda = altura(a->esquerda);

    int alt_direita = altura(a->direita);


    return 1 + (alt_esquerda > alt_direita ? alt_esquerda : alt_direita);
}

*/