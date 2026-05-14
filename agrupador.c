#include "agrupador.h"

struct agrupador{
    int k;
    Ponto **pontos;
    int n_pontos;
    int tam_max_vetor;
    Aresta *piscinaArestas;
    Aresta **arestas;
    int total_arestas;
    UF *uf;
    NoArvore *piscinaNosArvore;
    NoArvore **arvore;
    Grupo **grupos;
    int contador_grupos;
};

Agrupador *criaAgrupador(int k){
    Agrupador *a = (Agrupador *) malloc (sizeof(Agrupador));
    a->k = k;
    return a;
}

void lePontos(Agrupador *a, FILE *entrada){
    a->tam_max_vetor = 10;
    a->n_pontos = 0;
    a->pontos = criaVetorPontos(a->tam_max_vetor);

    char *linha = NULL;
    size_t tam = 0;
    

    while(getline(&linha, &tam, entrada) != -1){

        if(a->n_pontos >= a->tam_max_vetor){
            a->tam_max_vetor *= 2;
            
            a->pontos = realocaVetorPontos(a->pontos, a->tam_max_vetor);
            for(int i = a->n_pontos; i < a->tam_max_vetor; i++){
                a->pontos[i] = criaPonto();
            }
        }
        
        char *token = strtok(linha, ",");
        adicionaIdPonto(a->pontos[a->n_pontos], token);
        
        while(token != NULL){
            token = strtok(NULL, ",");
            if(token != NULL){
                float valor = atof(token);
                adicionaValorPonto(a->pontos[a->n_pontos], valor);
                
            }
        }
        
        a->n_pontos++;
    }

    free(linha);
}

void preencheOrdenaArestas(Agrupador *a){
    
    a->total_arestas = (a->n_pontos * (a->n_pontos - 1)) / 2;
    a->piscinaArestas = criaPiscinaAresta(a->total_arestas);
    a->arestas = criaVetorArestas(a->total_arestas, a->piscinaArestas);
    
    preencheVetorComDistancias(a->arestas, a->pontos, a->n_pontos);
    ordenaArestas(a->arestas, a->total_arestas);
    
}

void criaMST(Agrupador *a){
    int max_nos = (a->n_pontos - 1) * 2 + 10;
    
    int contadorArvore = 0;

    a->uf = UF_init(a->n_pontos);
    a->arvore = criaVetorArvores(a->n_pontos, max_nos);
    a->piscinaNosArvore = criaNoArvore(max_nos);

    int arestasAdicionadas = 0;

     for(int i = 0; i < a->total_arestas; i++){
        Aresta *atual = a->arestas[i];

        if(UF_find(a->uf,getOrigemAresta(atual)) != UF_find(a->uf, getDestinoAresta(atual))){
            addArestaNaArvoreComPiscina(atual, a->arvore, a->piscinaNosArvore, &contadorArvore, max_nos);
            arestasAdicionadas++;
            UF_union(a->uf,getOrigemAresta(atual), getDestinoAresta(atual));

            if(arestasAdicionadas >= (a->n_pontos - a->k)){
                break;
            }
        }
    }
}

void criaOrdenaGrupos(Agrupador *a){
    
    a->contador_grupos = 0;
    a->grupos = criaVetorGrupo(a->k);
    percorreArvore(a->arvore, a->n_pontos, a->pontos, a->grupos, &a->contador_grupos);
    
    ordenaGrupos(a->grupos, a->contador_grupos);
}

void imprimeGruposArquivo(Agrupador *a, FILE *saida){
    imprimeVetorGrupoArquivo(a->grupos, a->contador_grupos, saida);
}

void liberaAgrupador(Agrupador *a){
    liberaVetorPontos(a->pontos, a->tam_max_vetor);
    liberaVetorGrupos(a->grupos, a->k);
    liberaVetorArestas(a->arestas, a->piscinaArestas);
    liberaVetorArvores(a->arvore, a->piscinaNosArvore);
    UF_destroy(a->uf);
    free(a);
}
