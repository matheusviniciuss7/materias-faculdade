#include <stdio.h>

main() {
    int valores[6];
    
    // Leitura dos 6 valores inteiros pares com validação
    printf("Digite 6 valores inteiros PARES:\n");
    for (int i = 0; i < 6; i++) {
        do {
            printf("Valor %d (par): ", i + 1);
            scanf("%d", &valores[i]);
            
            if (valores[i] % 2 != 0) {
                printf("Valor invalido! Digite apenas numeros pares.\n");
            }
        } while (valores[i] % 2 != 0);
    }
    
    printf("\nValores pares digitados (ordem inversa):\n");
    for (int i = 5; i >= 0; i--) {
        printf("%d\n", valores[i]);
    }
    
}
