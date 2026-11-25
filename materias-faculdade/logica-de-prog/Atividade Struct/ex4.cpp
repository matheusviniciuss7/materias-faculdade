#include <stdio.h>
#include <string.h>

struct Produto {
    int cod;
    char nome[50];
    float preco;
    int est;
};

struct Venda {
    struct Produto prod;
    int qtd;
    float total;
};

main() {
    struct Produto p[10];
    struct Venda v[20];
    float fatProd[10] = {0};
    int totP = 0, totV = 0, op, i, cod, q, pos;

    do {
        printf("\n1. Cadastrar produto\n2. Registrar venda\n3. Relatorio\n0. Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            if (totP >= 10) {
                printf("Limite atingido!\n");
            } else {
                printf("Codigo: ");
                scanf("%d", &p[totP].cod);

                printf("Nome: ");
                scanf(" %49[^\n]", p[totP].nome);

                printf("Preco: ");
                scanf("%f", &p[totP].preco);

                printf("Estoque: ");
                scanf("%d", &p[totP].est);

                totP++;
            }
        } else if (op == 2) {
            if (totV >= 20) {
                printf("Limite atingido!\n");
            } else {
                printf("Codigo do produto: ");
                scanf("%d", &cod);

                pos = -1;
                for (i = 0; i < totP; i++) {
                    if (p[i].cod == cod) {
                        pos = i;
                    }
                }

                if (pos == -1) {
                    printf("Nao encontrado!\n");
                } else {
                    printf("Quantidade: ");
                    scanf("%d", &q);

                    if (q > p[pos].est) {
                        printf("Estoque insuficiente!\n");
                    } else {
                        p[pos].est -= q;
                        v[totV].prod = p[pos];
                        v[totV].qtd = q;
                        v[totV].total = q * p[pos].preco;

                        fatProd[pos] += v[totV].total;
                        totV++;
                        printf("Venda registrada!\n");
                    }
                }
            }
        } else if (op == 3) {
            float fatGeral = 0;
            int maior = 0;

            for (i = 0; i < totV; i++) {
                fatGeral += v[i].total;
            }

            for (i = 1; i < totP; i++) {
                if (fatProd[i] > fatProd[maior]) {
                    maior = i;
                }
            }

            printf("Faturamento total: R$ %.2f\n", fatGeral);
            if (totP > 0 && fatProd[maior] > 0) {
                printf("Mais faturado: %s (R$ %.2f)\n", p[maior].nome, fatProd[maior]);
            }
        }
    } while (op != 0);
}
