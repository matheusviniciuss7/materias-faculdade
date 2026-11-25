#include <stdio.h>
#include <string.h>

struct Func {
    int cod;
    char nome[50];
    char cargo[30];
    float salBase;
    int he;
    float salLiq;
};

main() {
    struct Func f[8];
    int n, i, maior = 0;
    float vHora, vExtra, bruto, desc, total = 0;

    printf("Qtd de funcionarios (max 8): ");
    scanf("%d", &n);
    if (n > 8) {
    	printf("Qtd de funcionarios invalido");
	} else {
		for (i = 0; i < n; i++) {
        printf("\nFuncionario %d\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &f[i].cod);
        getchar();

        printf("Nome: ");
        scanf(" %49[^\n]", f[i].nome);

        printf("Cargo: ");
        scanf(" %49[^\n]", f[i].cargo);

        printf("Salario base: ");
        scanf("%f", &f[i].salBase);

        printf("Horas extras: ");
        scanf("%d", &f[i].he);

        vHora = f[i].salBase / 160.0;
        vExtra = vHora * 1.5;
        bruto = f[i].salBase + (f[i].he * vExtra);
        desc = bruto * 0.10;
        f[i].salLiq = bruto - desc;

        total += f[i].salLiq;
    }

    printf("\n--- Folha ---\n");
    for (i = 0; i < n; i++) {
        printf("Cod: %d | %s (%s) | Liquido: R$ %.2f\n",
               f[i].cod, f[i].nome, f[i].cargo, f[i].salLiq);

        if (f[i].salLiq > f[maior].salLiq) {
            maior = i;
        }
    }

    printf("\nMaior salario: %s (R$ %.2f)\n", f[maior].nome, f[maior].salLiq);
    printf("Custo total: R$ %.2f\n", total);
	}
}
