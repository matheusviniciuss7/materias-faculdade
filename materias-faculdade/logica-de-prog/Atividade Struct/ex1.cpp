#include <stdio.h>
#include <string.h>

struct Aluno {
    int mat;
    char nome[50];
    float n1;
    float n2;
    float media;
};

float calcMedia(float a, float b) {
    return (a + b) / 2;
}

main() {
    struct Aluno a[10];
    float soma, mediaGeral;
    int i, maior, menor, acima;

    for (i = 0; i < 10; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &a[i].mat);
        getchar();

        printf("Nome: ");
        scanf(" %49[^\n]", a[i].nome);

        printf("Nota 1: ");
        scanf("%f", &a[i].n1);

        printf("Nota 2: ");
        scanf("%f", &a[i].n2);

        a[i].media = calcMedia(a[i].n1, a[i].n2);
        soma += a[i].media;
    }

    mediaGeral = soma / 10.0;

    printf("\n--- Resultados ---\n");
    for (i = 0; i < 10; i++) {
        printf("Mat: %d | Nome: %s | Media: %.2f ", a[i].mat, a[i].nome, a[i].media);

        if (a[i].media >= 6.0) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }

        if (a[i].media > a[maior].media) {
            maior = i;
        }
        if (a[i].media < a[menor].media) {
            menor = i;
        }
        if (a[i].media > mediaGeral) {
            acima++;
        }
    }

    printf("\nMaior media: %s (%.2f)\n", a[maior].nome, a[maior].media);
    printf("Menor media: %s (%.2f)\n", a[menor].nome, a[menor].media);
    printf("Media geral: %.2f\n", mediaGeral);
    printf("Acima da media geral: %d\n", acima);

}
