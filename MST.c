#include "MST.h"
#include "aresta.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

struct noarvore {
    int id;
    NoArvore *vizinho;
};

NoArvore **criaVetorArvores(int n, int max_nos){
    NoArvore **arvore = (NoArvore **) calloc (n, sizeof(NoArvore*));

    if(arvore == NULL){
        fprintf(stderr, "Erro ao alocar memoria para vetor de arvores\n");
        exit(EXIT_FAILURE);
    }

    return arvore;
}

NoArvore *criaNoArvore(int n){
    NoArvore *no = (NoArvore *) calloc (n,  sizeof(NoArvore));

    if(no == NULL){
        fprintf(stderr, "Erro ao alocar memoria para no de arvore\n");
        exit(EXIT_FAILURE);
    }
    
    no->vizinho = NULL;
    return no;
}


void addArestaNaArvoreComPiscina(Aresta *a, NoArvore **arvore, NoArvore *pool, int *contador_pool, int max_nos){
    
    if (*contador_pool + 1 >= max_nos) {
        fprintf(stderr, "Erro: pool de nos esgotado!\n");
        exit(1);
    }
    
    NoArvore *noB = &pool[*contador_pool];
    (*contador_pool)++;
    noB->id = getDestinoAresta(a);
    noB->vizinho = arvore[getOrigemAresta(a)];
    arvore[getOrigemAresta(a)] = noB;

    NoArvore *noA = &pool[*contador_pool];
    (*contador_pool)++;
    noA->id = getOrigemAresta(a);
    noA->vizinho = arvore[getDestinoAresta(a)];
    arvore[getDestinoAresta(a)] = noA;
}

void percorreArvore(NoArvore **arvore, int n_pontos, Ponto *pontos, Grupo **grupos, int *contador_grupo){

    int *verificador = (int *) calloc (n_pontos, sizeof(int));
    int  *pilha = (int *) malloc (n_pontos * sizeof(int));


    for(int i = 0; i < n_pontos; i++){
        if(verificador[i] == 0){

            int topo = 0;
            pilha[topo] = i;
            topo++;

            while(topo > 0){
                topo--;
                int idAtual = pilha[topo];

                if(verificador[idAtual]){
                    continue;
                }
                verificador[idAtual] = 1;

                adicionaElementoGrupo(grupos[*contador_grupo], getIdUnico(getPonto(pontos, idAtual)));

                NoArvore *vizinho = arvore[idAtual];
                while(vizinho != NULL){
                    if(verificador[vizinho->id] == 0){
                        pilha[topo] = vizinho->id;
                        topo++;
                    }
                    vizinho = vizinho->vizinho;
                }
            }

            (*contador_grupo)++;
            
    }

}
    free(verificador);
    free(pilha);
}

void liberaVetorArvores(NoArvore **arvore, NoArvore *piscina) {
    if (arvore == NULL) {
        return; 
    }
    free(piscina);
    free(arvore);
}
