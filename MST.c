#include "MST.h"
#include "aresta.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

struct noarvore {
    int id;
    double peso;
    NoArvore *vizinho;
};

NoArvore **criaVetorArvores(int n){
    NoArvore **arvore = (NoArvore **) malloc (n * sizeof(NoArvore*));

    return arvore;
}

void addArestaNaArvore(Aresta *a, NoArvore **arvore){
    NoArvore *noB = (NoArvore *) malloc (sizeof(NoArvore));
    noB->id = getDestinoAresta(a);
    noB->vizinho = arvore[getOrigemAresta(a)];
    noB->peso = getPesoAresta(a);
    arvore[getOrigemAresta(a)] = noB;

    NoArvore *noA = (NoArvore *) malloc (sizeof(NoArvore));
    noA->id = getOrigemAresta(a);
    noA->vizinho = arvore[getDestinoAresta(a)];
    noA->peso = getPesoAresta(a);
    arvore[getDestinoAresta(a)] = noA;
}

void percorreArvore(NoArvore **arvore, int n_pontos, Ponto **pontos, Grupo **grupos, int *contador_grupo){

    int *verificador = (int *) calloc (n_pontos, sizeof(int));


    for(int i = 0; i < n_pontos; i++){
        if(verificador[i] == 0){
            int tamanhoGrupo = 0;
            DFS(i, arvore, verificador, &tamanhoGrupo, grupos, *contador_grupo, pontos);
            (*contador_grupo)++;
        }
    }
}

// Função recursiva da Busca em Profundidade
void DFS(int id_atual, NoArvore** arvore, int* visitado, int* tamanho_grupo, Grupo **grupos, int contador_grupo, Ponto **pontos) {
    // 1. Marca o ponto atual como visitado (para não entrar em loop infinito)
    visitado[id_atual] = 1;

    adicionaElementoGrupo(grupos[contador_grupo], id_atual, getIdUnico(pontos[id_atual]));

    // 3. Olha para todos os vizinhos desse ponto na lista encadeada
    NoArvore* vizinho = arvore[id_atual];
    while (vizinho != NULL) {
        int id_do_vizinho = vizinho->id;

        // Se o vizinho ainda não foi visitado, a DFS "pula" para ele
        if (visitado[id_do_vizinho] == 0) {
            DFS(id_do_vizinho, arvore, visitado, tamanho_grupo, grupos, contador_grupo, pontos);
        }
        
        // Vai para o próximo vizinho na lista encadeada
        vizinho = vizinho->vizinho;
    }
}

// Supondo que você tenha um vetor com os dados dos pontos para poder imprimir o nome deles
// Note que agora o terceiro parâmetro é Ponto**
void imprimir_arvore_debug(NoArvore** arvore, int n_pontos, Ponto** vetor_de_pontos) {
    printf("--- Estrutura da Arvore Geradora (DEBUG) ---\n");

    
    for (int i = 0; i < n_pontos; i++) {
        // Usamos -> para acessar o nome, pois vetor_de_pontos[i] é um ponteiro
        printf("Ponto %s esta ligado a: ", getIdUnico(vetor_de_pontos[i])); 
        
        NoArvore* atual = arvore[i];
        while (atual != NULL) {
            // Usamos o id_vizinho como índice no vetor_de_pontos para achar o nome do vizinho
            printf("%s (peso: %.2f) -> ", getIdUnico(vetor_de_pontos[atual->id]), atual->peso);
            atual = atual->vizinho;
        }
        printf("NULL\n");
    }
}