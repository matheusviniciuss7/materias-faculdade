#include <stdio.h>
#include <string.h>
#define MAX 20

int main() {
    int codigo[MAX];
    char nome[MAX][50];
    float preco[MAX];
    int quantidade[MAX];
    
    int total = 0;
    int opcao;
    int codigoBusca, i, j, encontrado;

    do {
        printf("\n--- SISTEMA DE CADASTRO DE PRODUTOS ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Listar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            opcao = -1; 
        }

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Novo Cadastro (Posicao %d) ---\n", total);
                    printf("Codigo: ");
                    scanf("%d", &codigo[total]);
                    
                    printf("Nome: ");
                    scanf(" %[^\n]", nome[total]); 
                    
                    printf("Preco: ");
                    scanf("%f", &preco[total]);
                    
                    printf("Quantidade: ");
                    scanf("%d", &quantidade[total]);
                    
                    total++;
                    printf("Cadastro realizado com sucesso!\n");
                } else {
                    printf("\nLimite maximo de cadastros atingido.\n");
                }
                break;

            case 2:
                printf("\n--- Consultar Produto ---\n");
                printf("Digite o codigo procurado: ");
                scanf("%d", &codigoBusca);
                encontrado = 0;
                
                for (i = 0; i < total; i++) {
                    if (codigo[i] == codigoBusca) {
                        printf("\nRegistro Encontrado:\n");
                        printf("Codigo: %d\n", codigo[i]);
                        printf("Nome: %s\n", nome[i]);
                        printf("Preco: %.2f\n", preco[i]);
                        printf("Quantidade: %d\n", quantidade[i]);
                        encontrado = 1;
                        break;
                    }
                }
                
                if (encontrado == 0) {
                    printf("\nRegistro nao encontrado.\n");
                }
                break;

            case 3:
                printf("\n--- Lista de Produtos ---\n");
                if (total == 0) {
                    printf("Nenhum registro cadastrado.\n");
                } else {
                    for (i = 0; i < total; i++) {
                        printf("Codigo: %d | Nome: %s | Preco: R$ %.2f | Quantidade: %d\n", 
                               codigo[i], nome[i], preco[i], quantidade[i]);
                    }
                    printf("Total de registros: %d\n", total);
                }
                break;

            case 4:
                printf("\n--- Alterar Produto ---\n");
                printf("Digite o codigo do produto que deseja alterar: ");
                scanf("%d", &codigoBusca);
                encontrado = 0;
                
                for (i = 0; i < total; i++) {
                    if (codigo[i] == codigoBusca) {
                        printf("Produto encontrado. Insira os novos dados:\n");
                        
                        printf("Novo Codigo: ");
                        scanf("%d", &codigo[i]);
                        
                        printf("Novo Nome: ");
                        scanf(" %[^\n]s", nome[i]);
                        
                        printf("Novo Preco: ");
                        scanf("%f", &preco[i]);
                        
                        printf("Nova Quantidade: ");
                        scanf("%d", &quantidade[i]);
                        
                        printf("Registro alterado com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }
                
                if (encontrado == 0) {
                    printf("\nRegistro nao encontrado.\n");
                }
                break;

            case 5:
                printf("\n--- Excluir Produto ---\n");
                printf("Digite o codigo do produto que deseja excluir: ");
                scanf("%d", &codigoBusca);
                encontrado = 0;
                
                for (i = 0; i < total; i++) {
                    if (codigo[i] == codigoBusca) {
                        for (j = i; j < total - 1; j++) {
                            codigo[j] = codigo[j + 1];
                            strcpy(nome[j], nome[j + 1]);
                            preco[j] = preco[j + 1];
                            quantidade[j] = quantidade[j + 1];
                        }
                        total--;
                        printf("Registro excluido com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }
                
                if (encontrado == 0) {
                    printf("\nNao foi possivel excluir. Registro nao encontrado.\n");
                }
                break;

            case 0:
                printf("\nEncerrando o sistema. Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);    
}
