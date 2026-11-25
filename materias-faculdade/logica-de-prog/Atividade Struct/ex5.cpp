#include <stdio.h>
#include <string.h>

struct Data {
    int d, m, a;
};

struct Paciente {
    int cod;
    char nome[50];
    char tel[20];
};

struct Consulta {
    struct Paciente pac;
    struct Data dt;
    char desc[100];
};

main() {
    struct Paciente p[15];
    struct Consulta c[30];
    int totP = 0, totC = 0, op, i, j, cod, pos;

    do {
        printf("\n1. Cadastrar paciente\n2. Nova consulta\n3. Buscar por paciente\n4. Buscar por data\n5. Total por paciente\n0. Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            if (totP >= 15) {
                printf("Limite atingido!\n");
            } else {
                printf("Codigo: ");
                scanf("%d", &p[totP].cod);
                getchar();

                printf("Nome: ");
                scanf(" %49[^\n]", p[totP].nome);

                printf("Telefone: ");
                scanf(" %19[^\n]", p[totP].tel);

                totP++;
            }
        } else if (op == 2) {
            if (totC >= 30) {
                printf("Limite atingido!\n");
            } else {
                printf("Codigo do paciente: ");
                scanf("%d", &cod);

                pos = -1;
                for (i = 0; i < totP; i++) {
                    if (p[i].cod == cod) {
                        pos = i;
                    }
                }

                if (pos == -1) {
                    printf("Paciente nao encontrado!\n");
                } else {
                    c[totC].pac = p[pos];

                    printf("Data (d m a): ");
                    scanf("%d %d %d", &c[totC].dt.d, &c[totC].dt.m, &c[totC].dt.a);
                    getchar();

                    printf("Descricao: ");
                    scanf(" %99[^\n]", c[totC].desc);

                    totC++;
                }
            }
        } else if (op == 3) {
            printf("Codigo do paciente: ");
            scanf("%d", &cod);
            int achou = 0;

            for (i = 0; i < totC; i++) {
                if (c[i].pac.cod == cod) {
                    printf("%d/%d/%d - %s\n", c[i].dt.d, c[i].dt.m, c[i].dt.a, c[i].desc);
                    achou = 1;
                }
            }
            if (!achou) printf("Nenhuma consulta.\n");

        } else if (op == 4) {
            int d, m, a, achou = 0;
            printf("Data (d m a): ");
            scanf("%d %d %d", &d, &m, &a);

            for (i = 0; i < totC; i++) {
                if (c[i].dt.d == d && c[i].dt.m == m && c[i].dt.a == a) {
                    printf("%s - %s\n", c[i].pac.nome, c[i].desc);
                    achou = 1;
                }
            }
            if (!achou) printf("Nenhuma consulta.\n");

        } else if (op == 5) {
            if (totP == 0) {
                printf("Nenhum paciente.\n");
            } else {
                int max = -1, maior = 0, cont;

                for (i = 0; i < totP; i++) {
                    cont = 0;
                    for (j = 0; j < totC; j++) {
                        if (c[j].pac.cod == p[i].cod) {
                            cont++;
                        }
                    }
                    printf("%s: %d consulta(s)\n", p[i].nome, cont);

                    if (cont > max) {
                        max = cont;
                        maior = i;
                    }
                }
                if (max > 0) {
                    printf("Mais atendido: %s (%d)\n", p[maior].nome, max);
                }
            }
        }
    } while (op != 0);
}
