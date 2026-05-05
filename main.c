#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "UF.h"
#include "aresta.h"
#include "matriz.h"
#include "MST.h"
#include "quickSort.h"
#include <time.h>



int main(int argc, char *argv[]){

    char *arqEntrada = strdup(argv[1]);
    FILE *entrada = fopen(arqEntrada, "r");
    int k = atoi(argv[2]);

    clock_t inicio, fim;
    double tempo_leitura, tempo_distancias, tempo_ordenacao, tempo_mst;

    Ponto **pontos = criaVetorPontos();

    free(arqEntrada);
    
    char *linha = NULL;
    size_t tam = 0;
    int n_pontos = 0;
    int tam_max_vetor = 10;
    
    inicio = clock();

    while(getline(&linha, &tam, entrada) != -1){

        if(n_pontos >= tam_max_vetor){
            tam_max_vetor *= 2;

            pontos = realocaVetorPontos(pontos, tam_max_vetor);
            for(int i = n_pontos; i < tam_max_vetor; i++){
                pontos[i] = criaPonto();
            }
        }
        
        char *token = strtok(linha, ",");
        adicionaIdPonto(pontos[n_pontos], token);
        
        while(token != NULL){
            token = strtok(NULL, ",");
            if(token != NULL){
                float valor = atof(token);
                adicionaValorPonto(pontos[n_pontos], valor);
                
            }
        }
        
        n_pontos++;
    }

    fim = clock();
    tempo_leitura = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    fclose(entrada);
    
    inicio = clock();
    float **matrizDistancias = criaMatriz(n_pontos);
    preencheMatrizComDistancias(matrizDistancias, n_pontos, pontos);

    fim = clock();

    tempo_distancias =  ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    int totalArestas = (n_pontos * (n_pontos - 1)) / 2;

    Aresta **arestas = criaVetorArestas(totalArestas);
    preencheVetorComDistancias(arestas, matrizDistancias, n_pontos);

    fim = clock();

    double tempo_preenche_arestas = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    ordenaArestas(arestas, totalArestas);
    //quickSort(arestas, 0, totalArestas - 1);
    fim = clock();
    double tempo_ordena_arestas = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    UF *uf = UF_init(n_pontos);
    NoArvore **arvore = criaVetorArvores(n_pontos);

    int arestasAdicionadas = 0;

    inicio = clock();
     for(int i = 0; i < totalArestas; i++){
        Aresta *atual = arestas[i];
        int src = getOrigemAresta(atual);
        int dst = getDestinoAresta(atual);

        if(UF_find(uf,getOrigemAresta(atual)) != UF_find(uf, getDestinoAresta(atual))){
            addArestaNaArvore(atual, arvore);
            arestasAdicionadas++;

            UF_union(uf,getOrigemAresta(atual), getDestinoAresta(atual));

            if(arestasAdicionadas >= (n_pontos - k)){
                break;
            }
        }
    }

    fim = clock();

    double tempo_uf =  ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    int contador_grupos = 0;
    Grupo **grupos = criaVetorGrupo(n_pontos);
    percorreArvore(arvore, n_pontos, pontos, grupos, &contador_grupos);
    fim = clock();
    
    double tempo_percorre_arvore = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    
    ordenaGrupos(grupos, contador_grupos);

    fim = clock();
    double tempo_ordena_grupos = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    imprimeVetorGrupos(grupos, contador_grupos);
    printf("N° de grupos: %d\n", contador_grupos);
    
    liberaMatriz(matrizDistancias, n_pontos);
    free(linha);
    liberaVetorPontos(pontos, tam_max_vetor);
    liberaVetorArestas(arestas, totalArestas);
    liberaVetorGrupos(grupos, n_pontos);
    liberaVetorArvores(arvore, n_pontos);

    UF_destroy(uf);

    printf("Tempo de leitura: %.4f segundos\n", tempo_leitura);
    printf("Tempo de cálculo das distâncias: %.4f segundos\n", tempo_distancias);
    printf("Tempo de preenchimento do vetor de arestas: %.4f segundos\n", tempo_preenche_arestas);
    printf("Tempo de ordenação das arestas: %.4f segundos\n", tempo_ordena_arestas);
    printf("Tempo de execução do algoritmo de Kruskal: %.4f segundos\n", tempo_uf);
    printf("Tempo de percurso da árvore para formar os grupos: %.4f segundos\n", tempo_percorre_arvore);
    printf("Tempo de ordenação dos grupos: %.4f segundos\n", tempo_ordena_grupos);

    return 0;

}


