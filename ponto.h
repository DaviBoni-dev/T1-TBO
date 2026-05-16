#ifndef PONTO_H
#define PONTO_H

/** @brief Estrutura que representa um ponto no espaço n-dimensional.
 */
typedef struct ponto Ponto;

/**
 * @brief Cria uma estrutura Ponto e aloca memória para ela
 * 
 * @return Ponto* - Ponteiro para o ponto criado
 */
Ponto *criaPonto(Ponto *ponto);

/**
 * @brief Cria um vetor de pontos e aloca memória para ele
 * 
 * @return Ponto** - Ponteiro para o vetor de pontos criado
 */
Ponto *criaVetorPontos(int n);

/**
 * @brief Adiciona um ID único a um ponto
 * 
 * @param p O ponto ao qual o ID será adicionado
 * @param id O ID a ser adicionado
 */
void adicionaIdPonto(Ponto *p, char *id);

/**
 * @brief Retorna o ID único de um ponto
 * 
 * @param p O ponto do qual o ID será retornado
 * @return char* - O ID único do ponto
 */
char *getIdUnico(Ponto *p);

/**
 * @brief Realoca um vetor de pontos
 * 
 * @param p O vetor de pontos a ser realocado
 * @param n O novo tamanho do vetor
 * @return Ponto** - Ponteiro para o vetor de pontos realocado
 */
Ponto *realocaVetorPontos(Ponto *p, int n);


/**
 * @brief Calcula a distância euclidiana entre dois pontos
 * 
 * @param p1 O primeiro ponto
 * @param p2 O segundo ponto
 * @return double - A distância euclidiana entre os dois pontos
 */
double calculaDistanciaEuclidiana(Ponto *p1, Ponto *p2);

/**
 * @brief Adiciona um valor de coordenada a um ponto
 * 
 * @param p O ponto ao qual o valor será adicionado
 * @param valor O valor a ser adicionado
 */
void adicionaValorPonto(Ponto *p, double valor);

/**
 * @brief Obtém um ponto específico de um vetor de pontos
 * 
 * @param p Vetor de pontos do qual o ponto será obtido
 * @param i Índice do ponto a ser obtido
 * @return Ponto* 
 */
Ponto *getPonto(Ponto *p, int i);

/**
 * @brief Libera a memória alocada para um ponto
 * 
 * @param p O ponto a ser liberado
 */
void liberaPonto(Ponto *p);

/**
 * @brief Libera a memória alocada para um vetor de pontos
 * 
 * @param pontos O vetor de pontos a ser liberado
 * @param n O tamanho do vetor
 */
void liberaVetorPontos(Ponto *pontos, int n);

#endif 
