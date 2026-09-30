#include <stdio.h>

int main() {
    float A[10];
    float B[10];
    
    printf("Digite 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%f", &A[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        B[i] = A[i] * A[i];
    }
    
    printf("\n Vetor Original (A) \n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");
    
    printf("\n Vetor dos Quadrados (B) \n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", B[i]);
    }
    printf("\n");

}
