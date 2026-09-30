#include <stdio.h>

main() {
    float valores[5];
    float soma = 0.0;
    float maior, menor, media;
    
    printf("Digite 5 valores:\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%f", &valores[i]);
        
        soma += valores[i];
    }
    
    maior = valores[0];
    menor = valores[0];
    
    for (int i = 1; i < 5; i++) {
        if (valores[i] > maior) {
            maior = valores[i];
        }
        if (valores[i] < menor) {
            menor = valores[i];
        }
    }
    
    media = soma / 5.0;
    
    printf("\n--- Valores Lidos ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", valores[i]);
    }
    printf("\n");
    
    printf("\nEstatisticas\n");
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);
    printf("Media dos valores: %.2f\n", media);
}
