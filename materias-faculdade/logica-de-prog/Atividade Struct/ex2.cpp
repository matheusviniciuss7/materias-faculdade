#include <stdio.h>
#include <string.h>

struct Produto {
    int cod;
    char nome[50];
    float preco;
    int qtd;
};

void atualizarEstoque(struct Produto p[], int pos, int q) {
    p[pos].qtd += q;
}

main() {
    struct Produto p[15];
    int tot = 0, op, cod, pos, q, i;

    do {
        printf("\n1. Cadastrar\n2. Listar\n3. Repor\n4. Vender\n5. Consultar\n0. Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            if (tot >= 15) {
                printf("Limite atingido!\n");
            } else {
                printf("Codigo: ");
                scanf("%d", &cod);
                
                pos = -1;
                for (i = 0; i < tot; i++) {
                    if (p[i].cod == cod) pos = i;
                }

                if (pos != -1) {
                    printf("Codigo ja existe!\n");
                } else {
                    p[tot].cod = cod;
                    getchar();
                    
                    printf("Nome: ");
                    scanf(" %49[^\n]", p[tot].nome);

                    printf("Preco: ");
                    scanf("%f", &p[tot].preco);

                    printf("Quantidade: ");
                    scanf("%d", &p[tot].qtd);

                    tot++;
                }
            }
        } else if (op == 2) {
            if (tot == 0) {
                printf("Lista vazia.\n");
            } else {
                float totalGeral = 0, item;
                int maior = 0;

                for (i = 0; i < tot; i++) {
                    item = p[i].preco * p[i].qtd;
                    totalGeral += item; 

                    if (item > (p[maior].preco * p[maior].qtd)) {
                        maior = i;
                    }

                    printf("Cod: %d | %s | Preco: %.2f | Qtd: %d | Total: %.2f\n",
                           p[i].cod, p[i].nome, p[i].preco, p[i].qtd, item);
                }
                printf("Total em estoque: R$ %.2f\n", totalGeral);
                printf("Maior valor: %s (R$ %.2f)\n",
                       p[maior].nome, p[maior].preco * p[maior].qtd);
            }
        } else if (op == 3) {
            printf("Codigo: ");
            scanf("%d", &cod);
            
            pos = -1;
            for (i = 0; i < tot; i++) {
                if (p[i].cod == cod) pos = i;
            }

            if (pos == -1) {
                printf("Nao encontrado.\n");
            } else {
                printf("Qtd a adicionar: ");
                scanf("%d", &q);
                atualizarEstoque(p, pos, q);
                printf("Novo estoque: %d\n", p[pos].qtd);
            }
        } else if (op == 4) {
            printf("Codigo: ");
            scanf("%d", &cod);
            
            pos = -1;
            for (i = 0; i < tot; i++) {
                if (p[i].cod == cod) pos = i;
            }

            if (pos == -1) {
                printf("Nao encontrado.\n");
            } else {
                printf("Qtd vendida: ");
                scanf("%d", &q);
                
                if (q > p[pos].qtd) {
                    printf("Estoque insuficiente!\n");
                } else {
                    atualizarEstoque(p, pos, -q); 
                    printf("Venda feita! Restante: %d\n", p[pos].qtd);
                }
            }
        } else if (op == 5) {
            printf("Codigo: ");
            scanf("%d", &cod);
            
            pos = -1;
            for (i = 0; i < tot; i++) {
                if (p[i].cod == cod) pos = i;
            }

            if (pos == -1) {
                printf("Nao encontrado.\n");
            } else {
                printf("%s | Preco: %.2f | Qtd: %d\n", p[pos].nome, p[pos].preco, p[pos].qtd);
            }
        }
    } while (op != 0);
}
