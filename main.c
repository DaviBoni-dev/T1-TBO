#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "UF.h"
#include "aresta.h"
#include "matriz.h"
#include "MST.h"
#include <math.h>



int main(int argc, char *argv[]){

    char *arqEntrada = strdup(argv[1]);

    FILE *entrada = fopen(arqEntrada, "r");
    int k = atoi(argv[2]);

    Ponto **pontos = criaVetorPontos();

    free(arqEntrada);
    
    char *linha = NULL;
    size_t tam = 0;
    int n_pontos = 0;
    int tam_max_vetor = 10;
    
    
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
            //printf("%s\n", token);
            token = strtok(NULL, ",");
            if(token != NULL){
                float valor = atof(token);
                adicionaValorPonto(pontos[n_pontos], valor);
                
            }
        }
        
        n_pontos++;
    }

    fclose(entrada);
    
    float **matrizDistancias = criaMatriz(n_pontos);
    preencheMatrizComDistancias(matrizDistancias, n_pontos, pontos);


    int totalArestas = (n_pontos * (n_pontos - 1)) / 2;

    Aresta **arestas = criaVetorArestas(totalArestas);
    preencheVetorComDistancias(arestas, matrizDistancias, n_pontos);


    ordenaArestas(arestas, totalArestas);

    UF *uf = UF_init(n_pontos);
    NoArvore **arvore = criaVetorArvores(n_pontos);

    int arestasAdicionadas = 0;

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


    int contador_grupos = 0;
    Grupo **grupos = criaVetorGrupo(n_pontos);
    percorreArvore(arvore, n_pontos, pontos, grupos, &contador_grupos);
    ordenaGrupos(grupos, contador_grupos);
    imprimeVetorGrupos(grupos, contador_grupos);
    printf("N° de grupos: %d\n", contador_grupos);
    
    liberaMatriz(matrizDistancias, n_pontos);
    free(linha);
    liberaVetorPontos(pontos, tam_max_vetor);
    liberaVetorArestas(arestas, totalArestas);
    liberaVetorGrupos(grupos, n_pontos);
    liberaVetorArvores(arvore, n_pontos);

    UF_destroy(uf);

    return 0;

}


