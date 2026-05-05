#ifndef PONTO_H
#define PONTO_H


typedef struct ponto Ponto;

/**
 * @brief 
 * 
 * @return Ponto* 
 */
Ponto *criaPonto();

/**
 * @brief 
 * 
 * @param p 
 * @param id 
 */
void adicionaIdPonto(Ponto *p, char *id);

char *getIdUnico(Ponto *p);

Ponto **realocaVetorPontos(Ponto **p, int n);
/**
 * @brief 
 * 
 * @param p1 
 * @param p2 
 * @return float 
 */
float calculaDistanciaEuclidiana(Ponto *p1, Ponto *p2);

/**
 * @brief 
 * 
 * @param p 
 * @param valor 
 */
void adicionaValorPonto(Ponto *p, float valor);

/**
 * @brief 
 * 
 * @return Ponto** 
 */
Ponto **criaVetorPontos();

/**
 * @brief 
 * 
 * @param p 
 */
void liberaPonto(Ponto *p);

/**
 * @brief 
 * 
 * @param p 
 */
void imprimePonto(Ponto *p);

/**
 * @brief 
 * 
 * @param pontos 
 * @param n 
 */
void imprimeVetorPontos(Ponto **pontos, int n);

/**
 * @brief 
 * 
 * @param pontos 
 * @param n 
 */
void liberaVetorPontos(Ponto **pontos, int n);

#endif /* PONTO_H */
