#include <stdio.h>

main() {
    float notas[15];
    float soma = 0.0;
    float media;

    printf("Digite a nota dos 15 alunos:\n");
    for (int i = 0; i < 15; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        
        soma += notas[i];
    }

    media = soma / 15.0;

    printf("\n--- Resultado ---\n");
    printf("Media geral da turma: %.2f\n", media);

}
