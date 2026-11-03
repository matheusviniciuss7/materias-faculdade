#include <stdio.h>
#include <string.h>

// 1 - CADASTRAR (IMPLEMENTADA)
void cadastrar(int codigo[], char nome[][15], int *total) {
    // Verificar se o cadastro esta cheio
    if (*total == 5) {
        printf("\nCadastro cheio!\n");
        return;
    }
    // Ler o codigo
    printf("\nDigite o codigo: ");
    scanf("%d", &codigo[*total]);
    getchar();
    // Ler o nome
    printf("Digite o nome: ");
    fgets(nome[*total], 15, stdin);
    // Atualizar o total de registros
    (*total)++;
    printf("\nCadastro realizado com sucesso!\n");
}

// 2 - CONSULTAR (COMPLETAR)
void consultar(int codigo[], char nome[][15], int total) {
    int busca;
    int encontrado = 0;

    if (total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    printf("\nDigite o codigo para consulta: ");
    scanf("%d", &busca);

    for (int i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            printf("\nRegistro encontrado:\n");
            printf("Codigo: %d\n", codigo[i]);
            printf("Nome: %s", nome[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nCodigo nao encontrado!\n");
    }
}

// 3 - LISTAR (COMPLETAR)
void listar(int codigo[], char nome[][15], int total) {
    if (total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    printf("\n===== LISTA DE REGISTROS =====\n");
    for (int i = 0; i < total; i++) {
        printf("Posicao %d -> Codigo: %d | Nome: %s", i + 1, codigo[i], nome[i]);
    }
}

// 4 - ALTERAR (COMPLETAR)
void alterar(int codigo[], char nome[][15], int total) {
    int busca;
    int encontrado = 0;

    if (total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    printf("\nDigite o codigo que deseja alterar: ");
    scanf("%d", &busca);

    for (int i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            encontrado = 1;

            printf("Digite o novo codigo: ");
            scanf("%d", &codigo[i]);
            getchar(); // Limpa o \n do buffer do teclado

            printf("Digite o novo nome: ");
            fgets(nome[i], 15, stdin);

            printf("\nRegistro alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nCodigo nao encontrado!\n");
    }
}

// 5 - EXCLUIR (COMPLETAR)
void excluir(int codigo[], char nome[][15], int *total) {
    int busca;
    int encontrado = 0;

    if (*total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    printf("\nDigite o codigo que deseja excluir: ");
    scanf("%d", &busca);

    for (int i = 0; i < *total; i++) {
        if (codigo[i] == busca) {
            encontrado = 1;

            // Desloca todos os registros posteriores uma posicao para a esquerda
            for (int j = i; j < *total - 1; j++) {
                codigo[j] = codigo[j + 1];
                strcpy(nome[j], nome[j + 1]);
            }

            // Atualiza a contagem total
            (*total)--;
            printf("\nRegistro excluido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nCodigo nao encontrado!\n");
    }
}

// PROGRAMA PRINCIPAL
int main(void) {
    int codigo[5];
    char nome[5][15];
    int total = 0;
    int opcao;

    do {
        printf("\n\n===== MENU =====");
        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(codigo, nome, &total);
                break;
            case 2:
                consultar(codigo, nome, total);
                break;
            case 3:
                listar(codigo, nome, total);
                break;
            case 4:
                alterar(codigo, nome, total);
                break;
            case 5:
                excluir(codigo, nome, &total);
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
