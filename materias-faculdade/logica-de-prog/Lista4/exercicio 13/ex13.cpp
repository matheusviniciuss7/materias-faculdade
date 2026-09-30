#include <stdio.h>

main() {
    float valores[5];
    int pos_maior = 0, pos_menor = 0;
    
    printf("Digite 5 valores:\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%f", &valores[i]);
    }
    
    for (int i = 1; i < 5; i++) {
        if (valores[i] > valores[pos_maior]) {
            pos_maior = i;
        }
        if (valores[i] < valores[pos_menor]) {
            pos_menor = i;
        }
    }
    
    printf("\n--- Resultado ---\n");
    printf("Maior valor: %.2f (na posicao/indice %d)\n", valores[pos_maior], pos_maior+1);
    printf("Menor valor: %.2f (na posicao/indice %d)\n", valores[pos_menor], pos_menor+1);
}
