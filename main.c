#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "UF.h"
#include "aresta.h"
#include "MST.h"
#include <time.h>


int main(int argc, char *argv[]){

    if(argc < 4){
        return 1;
    }

    char *arqEntrada = strdup(argv[1]);
    char *arqSaida = strdup(argv[3]);
    int k = atoi(argv[2]);
    FILE *entrada = fopen(arqEntrada, "r");

    int tam_max_vetor = 10;
    Ponto **pontos = criaVetorPontos(tam_max_vetor);

    char *linha = NULL;
    size_t tam = 0;
    int n_pontos = 0;
    

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

    fclose(entrada);
    
    int totalArestas = (n_pontos * (n_pontos - 1)) / 2;

    Aresta *pool = criaPiscinaAresta(totalArestas);
    Aresta **arestas = criaVetorArestas(totalArestas, pool);
    preencheVetorComDistancias(arestas, pontos, n_pontos);
    ordenaArestas(arestas, totalArestas);
    

    int max_nos = n_pontos * 2;
    int contadorArvore = 0;

    UF *uf = UF_init(n_pontos);
    NoArvore **arvore = criaVetorArvores(n_pontos, max_nos);
    NoArvore *piscina_nos = criaNoArvore(max_nos);

    int arestasAdicionadas = 0;

     for(int i = 0; i < totalArestas; i++){
        Aresta *atual = arestas[i];
        int src = getOrigemAresta(atual);
        int dst = getDestinoAresta(atual);

        if(UF_find(uf,getOrigemAresta(atual)) != UF_find(uf, getDestinoAresta(atual))){
            addArestaNaArvoreComPiscina(atual, arvore, piscina_nos, &contadorArvore);
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
    FILE *saida = fopen(arqSaida, "w");
    
    if (saida == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo %s\n", arqSaida);
        exit(1); 
    }
    
    imprimeVetorGrupoArquivo(grupos, contador_grupos, saida);

    
    free(linha);
    liberaVetorPontos(pontos, tam_max_vetor);
    liberaVetorGrupos(grupos, n_pontos);
    free(arvore);
    free(piscina_nos);
    free(pool);
    free(arestas);
    
    UF_destroy(uf);
    fclose(saida);
    free(arqEntrada);
    free(arqSaida);

    
    return 0;

}


