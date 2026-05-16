#ifndef UF_H
#define UF_H

typedef struct uf UF;

/**
 * @brief Inicializa uma estrutura Union-Find com N indíces
 * 
 * @param N Tamanho da estrutura 
 * @return UF* - Um ponteiro para a estrutura criada
 */
UF *UF_init(int N);

/**
 * @brief Encontra o representante de um elemento na estrutura Union-Find
 * 
 * @param uf A estrutura Union-Find
 * @param i O elemento para o qual encontrar o representante
 * @return int - O representante do elemento
 */
int UF_find(UF *uf, int i);

/**
 * @brief Verifica se dois elementos estão conectados na estrutura Union-Find
 * 
 * @param uf A estrutura Union-Find
 * @param p O primeiro elemento
 * @param q O segundo elemento
 * @return int - 1 se os elementos estiverem conectados, 0 caso contrário
 */
int connected(UF *uf, int p, int q);

/**
 * @brief Une dois elementos na estrutura Union-Find
 * 
 * @param uf A estrutura Union-Find
 * @param p O primeiro elemento
 * @param q O segundo elemento
 */
void UF_union(UF *uf, int p, int q);

/**
 * @brief Destroi a estrutura Union-Find
 * 
 * @param uf A estrutura Union-Find
 */
void UF_destroy(UF *uf);



#endif 
