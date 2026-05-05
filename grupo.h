#ifndef A7F48332_2C2B_4771_81FA_A0CE652E6AB2
#define A7F48332_2C2B_4771_81FA_A0CE652E6AB2


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grupo Grupo;

Grupo *criaGrupo();
Grupo **criaVetorGrupo(int n);
void adicionaElementoGrupo(Grupo *g, int elemento, char *id);
int comparaGrupo(const void* a, const void *b);
char **getIdElementosGrupo(Grupo *g);
void imprimeGrupo(Grupo *g);
void imprimeVetorGrupos(Grupo **g, int n);
int getQtdElementosGrupo(Grupo *g);
void ordenaGrupos(Grupo **g, int n);
void liberaGrupo(Grupo*g);
void liberaVetorGrupos(Grupo **g, int n);

#endif /* A7F48332_2C2B_4771_81FA_A0CE652E6AB2 */
