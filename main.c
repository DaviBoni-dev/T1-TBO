#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "UF.h"
#include "aresta.h"
#include "MST.h"
#include "agrupador.h"
#include <time.h>


int main(int argc, char *argv[]){

    if(argc < 4){
        printf("Insira os parâmetros corretamente: ./programa <arquivo_entrada> <k> <arquivo_saida>\n");
        return 1;
    }

    char *arqEntrada = strdup(argv[1]);
    char *arqSaida = strdup(argv[3]);
    int k = atoi(argv[2]);
    FILE *entrada = fopen(arqEntrada, "r");
    if(entrada == NULL){
        printf("Erro: Nao foi possivel criar o arquivo %s\n", arqEntrada);
        exit(1);
    }

    Agrupador *agrupador = criaAgrupador(k);
    
    lePontos(agrupador, entrada);
    preencheOrdenaArestas(agrupador);
    criaMST(agrupador);
    criaOrdenaGrupos(agrupador);
    
    FILE *saida = fopen(arqSaida, "w");
    if (saida == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo %s\n", arqSaida);
        exit(1); 
    }
    
    imprimeGruposArquivo(agrupador, saida);

    liberaAgrupador(agrupador);
    fclose(entrada);
    fclose(saida);
    free(arqEntrada);
    free(arqSaida);

    return 0;
}


