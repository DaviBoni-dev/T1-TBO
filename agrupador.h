#ifndef EFFABBC8_F532_4AB1_9BAD_ED402272F762
#define EFFABBC8_F532_4AB1_9BAD_ED402272F762

#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "aresta.h"
#include "UF.h"
#include "grupo.h"
#include "MST.h"
#include "agrupador.h"

typedef struct agrupador Agrupador;

Agrupador *criaAgrupador(int k);

void lePontos(Agrupador *a, FILE *entrada);

void preencheOrdenaArestas(Agrupador *a);

void criaMST(Agrupador *a);

void criaOrdenaGrupos(Agrupador *a);

void imprimeGruposArquivo(Agrupador *a, FILE *saida);

void liberaAgrupador(Agrupador *a);

#endif /* EFFABBC8_F532_4AB1_9BAD_ED402272F762 */
