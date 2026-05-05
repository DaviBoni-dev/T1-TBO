#ifndef UF_H
#define UF_H

typedef struct uf UF;

/**
 * @brief 
 * 
 * @param N 
 * @return UF* 
 */
UF *UF_init(int N);

/**
 * @brief 
 * 
 * @param uf 
 * @return int 
 */
int fcount(UF *uf);

/**
 * @brief 
 * 
 * @param uf 
 * @param i 
 * @return int 
 */
int UF_find(UF *uf, int i);

/**
 * @brief 
 * 
 * @param uf 
 * @param p 
 * @param q 
 * @return int 
 */
int connected(UF *uf, int p, int q);

/**
 * @brief 
 * 
 * @param uf 
 * @param p 
 * @param q 
 */
void UF_union(UF *uf, int p, int q);

/**
 * @brief 
 * 
 */
void UF_print(UF *uf);


void UF_destroy(UF *uf);



#endif /* UF_H */
