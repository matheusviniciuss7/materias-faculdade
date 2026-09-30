#include <stdio.h>

main() {
    int vetor[10];
    int maior, posicao;
    
    printf("Digite 10 valores inteiros:\n");
    for (int i = 0; i < 10; i++) {4
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    maior = vetor[0];
    posicao = 0;
    
    for (int i = 1; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posicao = i;
        }
    }
    
    printf("\n Vetor Digitado \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\n Resultado \n");
    printf("Maior elemento: %d\n", maior);
    printf("Encontrado na posicao (indice): %d\n", posicao);
    
}
