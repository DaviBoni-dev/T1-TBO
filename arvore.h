#ifndef _ARVORE_H
#define _ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arv Arv;
typedef struct forest Forest;

Forest *criaForest(int n);
void adicionaRaizForest(Forest *f, Arv *a, int indice);

void forest_imprime(Forest *f);
void arv_adiciona(int src, int dst, Forest *f);
void arv_imprime_visual(Arv* a, int nivel);

//Cria uma arvore vazia
Arv* arv_criavazia (void);

//cria uma arvore com a informacao do no raiz c, e com subarvore esquerda e e subarvore direita d
Arv* arv_cria (int c, Arv* e, Arv* d, int maxF);

//libera o espaco de memoria ocupado pela arvore a
Arv* arv_libera (Arv* a);

//retorna true se a arvore estiver vazia e false caso contrario
int arv_vazia (Arv* a);

//indica a ocorrencia (1) ou nao (0) do aluno (pela chave de busca mat)
int arv_pertence (Arv* a, int mat);

//imprime as informacoes dos nos da arvore
void arv_imprime (Arv* a);

//retorna o aluno do no raiz da arvore a
int arv_get_info(Arv* a);

//retorna a mae/pai de um dado no que contem o aluno com a matricula mat
Arv* arv_pai (Arv* a, int mat);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado aluno na arvore
int ocorrencias (Arv* a, int mat);

//retorna a altura da arvore a
int altura(Arv* a);

#endif