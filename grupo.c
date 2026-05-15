#include "grupo.h"
#include <string.h>

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

void liberaGrupo(Grupo*g){
    if(g != NULL){
        for(int i = 0; i < g->qtd_elementos; i++){
            free(g->idElementos[i]);
        }
        free(g->idElementos);
        free(g->elementos);
        free(g);
    }
}

void liberaVetorGrupos(Grupo **g, int n){
    for(int i = 0; i < n; i++){
        liberaGrupo(g[i]);
    }

    free(g);
}

int comparaGrupo(const void* a, const void *b){
    char *a1 = *(char**) a;
    char *b1 = *(char**) b;

   return strcmp(a1, b1);
}

int comparaGruposEntreSi(const void* a, const void *b){
    Grupo *a2 = *(Grupo **)a;
    Grupo *b2 = *(Grupo**)b;

    return strcmp(a2->idElementos[0], b2->idElementos[0]);
}

char **getIdElementosGrupo(Grupo *g){
    return g->idElementos;
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

void imprimeGrupoArquivo(Grupo *g, FILE *s){
    for(int i = 0; i < g->qtd_elementos; i++){
        fprintf(s, "%s", g->idElementos[i]);
        if(i != g->qtd_elementos - 1){
            fprintf(s, ",");
        }
    }

    fprintf(s,"\n");
}

void imprimeVetorGrupoArquivo(Grupo **g, int n, FILE *s){
    for(int i = 0; i < n; i++){
        if(g[i] != NULL) { 
            imprimeGrupoArquivo(g[i], s);
        }
    }
}

int getQtdElementosGrupo(Grupo *g){
    return g->qtd_elementos;
}

void ordenaGrupos(Grupo **g, int n){
    for(int i = 0; i < n; i++){
        qsort(g[i]->idElementos ,g[i]->qtd_elementos ,sizeof(char*), comparaGrupo);
    }

    qsort(g, n, sizeof(Grupo *), comparaGruposEntreSi);
}