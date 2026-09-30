#include <stdio.h>

main() {
    float vetor[10];
    int qtd_negativos = 0;
    float soma_positivos = 0.0;
    
    // Leitura dos 10 números reais
    printf("Digite 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%f", &vetor[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        if (vetor[i] < 0) {
            qtd_negativos++;
        } else if (vetor[i] > 0) {
            soma_positivos += vetor[i];
        }
    }
    
    printf("\nResultado\n");
    printf("Quantidade de numeros negativos: %d\n", qtd_negativos);
    printf("Soma dos numeros positivos: %.2f\n", soma_positivos);
    
}
