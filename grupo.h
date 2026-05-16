#ifndef GRUPO_H
#define GRUPO_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_MAX_ELEMENTOS_INICIAL 10

/**
 * @brief Estrutura de dados para representar um grupo de pontos, onde cada grupo possui um vetor de elementos (índices dos pontos) e um vetor de IDs correspondentes a esses elementos.
 * 
 */
typedef struct grupo Grupo;

/** @brief Cria um novo grupo.
 * @return Ponteiro para o grupo criado.
 */
Grupo *criaGrupo();

/** @brief Cria um vetor de grupos.
 * @param n Número de grupos no vetor.
 * @return Ponteiro para o vetor de grupos criado.
 */
Grupo **criaVetorGrupo(int n);

/** @brief Adiciona um elemento a um grupo.
 * @param g Ponteiro para o grupo.
 * @param id ID do elemento a ser adicionado.
 */
void adicionaElementoGrupo(Grupo *g, char *id);

/** @brief Compara dois grupos.
 * @param a Ponteiro para o primeiro grupo.
 * @param b Ponteiro para o segundo grupo.
 * @return Valor negativo se o primeiro grupo for menor, zero se forem iguais, positivo se o primeiro grupo for maior.
 */
int comparaGrupo(const void* a, const void *b);

/**
 * @brief Compara dois grupos entre si.
 * @param a Ponteiro para o primeiro grupo.
 * @param b Ponteiro para o segundo grupo.
 * @return Valor negativo se o primeiro item do primeiro grupo for menor, zero se forem iguais, positivo se o primeiro item do segundo grupo for maior.
 */
int comparaGruposEntreSi(const void* a, const void *b);

/** @brief Retorna os IDs dos elementos de um grupo.
 * @param g Ponteiro para o grupo.
 * @return Ponteiro para o vetor de IDs dos elementos do grupo.
 */
char **getIdElementosGrupo(Grupo *g);

/** @brief Retorna a quantidade de elementos de um grupo.
 * @param g Ponteiro para o grupo.
 * @return Quantidade de elementos do grupo.
 */
int getQtdElementosGrupo(Grupo *g);

/** @brief Ordena os grupos de um vetor de grupos.
 * @param g Ponteiro para o vetor de grupos.
 * @param n Número de grupos no vetor.
 */
void ordenaGrupos(Grupo **g, int n);

/** @brief Libera a memória alocada para um grupo.
 * @param g Ponteiro para o grupo.
 */
void liberaGrupo(Grupo*g);

/** @brief Libera a memória alocada para um vetor de grupos.
 * @param g Ponteiro para o vetor de grupos.
 * @param n Número de grupos no vetor.
 */
void liberaVetorGrupos(Grupo **g, int n);

/**
 * @brief Imprime um grupo em um arquivo, onde cada linha do arquivo contém os IDs dos elementos do grupo separados por vírgula.
 * 
 * @param g Ponteiro para o grupo.
 * @param s Ponteiro para o arquivo.
 */
void imprimeGrupoArquivo(Grupo *g, FILE *s);

/**
 * @brief Imprime um vetor de grupos em um arquivo
 * 
 * @param g Ponteiro para o vetor de grupos.
 * @param n Número de grupos no vetor.
 * @param s Ponteiro para o arquivo.
 */
void imprimeVetorGrupoArquivo(Grupo **g, int n, FILE *s);

#endif
