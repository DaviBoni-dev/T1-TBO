#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "UF.h"
#include "aresta.h"
#include "MST.h"
#include "agrupador.h"


int main(int argc, char *argv[]){

    if(argc < 4){
        fprintf(stderr, "Insira os parâmetros corretamente: ./programa <arquivo_entrada> <k> <arquivo_saida>\n");
        exit(EXIT_FAILURE);
    }

    char *arqEntrada = strdup(argv[1]);
    char *arqSaida = strdup(argv[3]);
    int k = atoi(argv[2]);
    FILE *entrada = fopen(arqEntrada, "r");
    if(entrada == NULL){
        fprintf(stderr, "Erro: Nao foi possivel ler o arquivo %s\n", arqEntrada);
        exit(EXIT_FAILURE);
    }

    Agrupador *agrupador = criaAgrupador(k);
    
    lePontos(agrupador, entrada);
    preencheOrdenaArestas(agrupador);
    criaMST(agrupador);
    criaOrdenaGrupos(agrupador);
    
    FILE *saida = fopen(arqSaida, "w");
    if (saida == NULL) {
        fprintf(stderr,"Erro: Nao foi possivel criar o arquivo %s\n", arqSaida);
        exit(EXIT_FAILURE); 
    }
    
    imprimeGruposArquivo(agrupador, saida);

    liberaAgrupador(agrupador);
    fclose(entrada);
    fclose(saida);
    free(arqEntrada);
    free(arqSaida);

    return 0;
}


