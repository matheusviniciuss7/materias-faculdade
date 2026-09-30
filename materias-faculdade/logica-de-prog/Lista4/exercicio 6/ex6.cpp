#include <stdio.h>

int main() {
    int vetor[10];
    int maior, menor;
    
    printf("Digite 10 valores inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    maior = vetor[0];
    menor = vetor[0];
    
    for (int i = 1; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    printf("\nResultado\n");
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    
}
