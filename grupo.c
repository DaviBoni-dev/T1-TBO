#include "grupo.h"

struct grupo {
    int *elementos;
    char **idElementos;
    int qtd_elementos;
    int qtd_max_elementos;
};

Grupo *criaGrupo(){
    Grupo *g = (Grupo *) malloc (sizeof(Grupo));
    g->qtd_max_elementos = 10;
    g->elementos = (int *) malloc (g->qtd_max_elementos * sizeof(int));
    g->idElementos = (char **) malloc (g->qtd_max_elementos * sizeof(char *));
    g->qtd_elementos = 0;

    return g;
}

Grupo **criaVetorGrupo(int n){
    Grupo **g = (Grupo **) malloc (n * sizeof(Grupo *));
    for(int i = 0; i < n; i++){
        g[i] = criaGrupo();
    }

    return g;
}

void adicionaElementoGrupo(Grupo *g, int elemento, char *id){
    if(g->qtd_elementos >= g->qtd_max_elementos){
        
        int novaCapac = 2 * g->qtd_max_elementos;

        int *temp = (int *) realloc (g->elementos, novaCapac * sizeof(int));
        char **ids_temp = (char **) realloc (g->idElementos, novaCapac * sizeof(char*));

        if(temp != NULL && ids_temp != NULL){
            g->qtd_max_elementos = novaCapac;
            g->elementos = temp;
            g->idElementos = ids_temp;
        }
        else{
            printf("Erro: Falta de memória ao adicionar valor!\n");
            exit(1);
            return;
        }

    }
    g->elementos[g->qtd_elementos] = elemento;
    g->idElementos[g->qtd_elementos] = strdup(id);
    g->qtd_elementos++;
}

void imprimeGrupo(Grupo *g){
    printf("Grupo com %d elementos :\n", g->qtd_elementos);
    for(int i = 0; i < g->qtd_elementos; i++){
        printf("%s, ", g->idElementos[i]);
    }

    printf("\n");
}

void imprimeVetorGrupos(Grupo **g, int n){
    for(int i = 0; i < n; i++){
        imprimeGrupo(g[i]);
    }
}

/*
    if(p->tamValoresPreenchidos == p->tamValoresTotal){
        float *temp = (float *) realloc (p->valores, (2 * p->tamValoresPreenchidos) * sizeof(float));

        if(temp != NULL){
            p->tamValoresTotal *= 2;
            p->valores = temp;
        } else {
           
            printf("Erro: Falta de memória ao adicionar valor!\n");
            return;
        }
    }

    p->valores[p->tamValoresPreenchidos] = valor;
    p->tamValoresPreenchidos++;
    p->m++;*/