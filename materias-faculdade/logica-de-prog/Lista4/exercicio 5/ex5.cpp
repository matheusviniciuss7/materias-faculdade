#include <stdio.h>

main() {
    int vetor[10];
    int pares = 0;
    
    printf("Digite 10 valores inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }
    
    printf("\nO vetor possui %d valores pares.\n", pares);
    
}
