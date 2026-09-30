#include <stdio.h>

main() {
    int vetor[8];
    int X, Y;
    
    printf("Digite 8 valores inteiros:\n");
    for (int i = 0; i < 8; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    printf("\nDigite duas posicoes (indices de 0 a 7):\n");
    
    do {
        printf("Digite a posicao X: ");
        scanf("%d", &X);
        if (X < 0 || X > 7) {
            printf("Posicao invalida! Tente um valor entre 0 e 7.\n");
        }
    } while (X < 0 || X > 7);
    
    do {
        printf("Digite a posicao Y: ");
        scanf("%d", &Y);
        if (Y < 0 || Y > 7) {
            printf("Posicao invalida! Tente um valor entre 0 e 7.\n");
        }
    } while (Y < 0 || Y > 7);
    
    int soma = vetor[X] + vetor[Y];
    
    printf("\nResultado\n");
    printf("Valor na posicao %d: %d\n", X, vetor[X]);
    printf("Valor na posicao %d: %d\n", Y, vetor[Y]);
    printf("Soma (vetor[%d] + vetor[%d]): %d\n", X, Y, soma);

}
