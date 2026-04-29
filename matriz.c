#include "matriz.h"

float **criaMatriz(int n){
    float **matrizDistancias = (float **) malloc (n * sizeof(float *));
    for(int i = 0; i < n; i++){
        matrizDistancias[i] = (float *) malloc (n * sizeof(float));
    }
    return matrizDistancias;
}

void imprimeMatriz(float **m, int n){
        for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            printf("%.2f ", m[i][j]);
        }

        printf("\n");
    }
}

void preencheMatrizComDistancias(float **m, int n, Ponto **pontos){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                m[i][j] = calculaDistanciaEuclidiana(pontos[i], pontos[j]);
            }
    }

}

void liberaMatriz(float **m, int n){
    for(int i = 0; i < n; i++){
        free(m[i]);
    }

    free(m);
}
