#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "UF.h"
#include "arvore.h"
#include "aresta.h"
#include "matriz.h"
#include <math.h>



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

    Aresta **arestas = criaVetorArestas(totalArestas);
    preencheVetorComDistancias(arestas, matrizDistancias, contador);


    ordenaArestas(arestas, totalArestas);

    UF *uf = UF_init(contador);
    Forest *forest = criaForest(contador);

    for(int i = 0; i < contador; i++){
        Arv *a = arv_cria(i, NULL, NULL, contador);
        adicionaRaizForest(forest,  a, i);
    }

    forest_imprime(forest);

     for(int i = 0; i < totalArestas; i++){
        Aresta *atual = arestas[i];
        int src = getOrigemAresta(atual);
        int dst = getDestinoAresta(atual);

        if(UF_find(uf,getOrigemAresta(atual)) != UF_find(uf, getDestinoAresta(atual))){
            arv_adiciona(src, dst, forest);
            UF_union(uf,getOrigemAresta(atual), getDestinoAresta(atual));
        }
    }

    printf("\n\n\n");
    forest_imprime(forest);
    printf("\n\n\n");


    //UF_print(uf);

    liberaMatriz(matrizDistancias, contador);

    free(linha);
    fclose(entrada);

    liberaVetorPontos(pontos, contador);

    return 0;

}


