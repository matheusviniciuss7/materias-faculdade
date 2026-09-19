#include <stdio.h>
#include <stdlib.h>

main() {
    char nome[50];
    float renda;
    float preco_carro;
    int codigo_status;

    int total_clientes = 0;
    int total_aprovados;
    int total_analise;
    int total_reprovados;

    int opcao = 1; 

    printf("SISTEMA DE ANALISE DE CREDITO\n");

    while (opcao == 1) {
        total_clientes++;

        printf("\n--- Cadastro do Cliente %d ---\n", total_clientes);

        printf("Introduza o nome do cliente: ");
        scanf(" %49[^\n]", nome);

        printf("Introduza a renda do cliente (R$): ");
        scanf("%f", &renda);

        printf("Introduza o preco do carro (R$): ");
        scanf("%f", &preco_carro);

        printf("\n-- Dados Registados --\n");
        printf("Nome: %s\n", nome);
        printf("Renda: R$ %.2f\n", renda);
        printf("Preco do Carro: R$ %.2f\n", preco_carro);


        if (renda >= preco_carro * 0.30) {
            codigo_status = 1;
        } else if (renda >= preco_carro * 0.15) {
            codigo_status = 2;
        } else {
            codigo_status = 3;
        }

        printf("\nStatus da Solicitacao: ");
        switch (codigo_status) {
            case 1:
                printf("APROVADO\n");
                total_aprovados++;
                break;
            case 2:
                printf("EM ANALISE\n");
                total_analise++;
                break;
            case 3:
                printf("REPROVADO\n");
                total_reprovados++;
                break;
            default:
                printf("ERRO DE CLASSIFICACAO\n");
        }

        printf("\nDeseja analisar outro cliente? (1 - Sim / 0 - Nao): ");
        scanf("%d", &opcao);

        while (opcao != 1 && opcao != 0) {
            printf("Opcao invalida! Deseja analisar outro cliente? (1 - Sim / 0 - Nao): ");
            scanf("%d", &opcao);
        }
    }
    
    system("cls");

    printf("\n==================================================\n");
    printf("                 RELATORIO FINAL                  \n");
    printf("==================================================\n");
    printf("Total de clientes analisados: %d\n", total_clientes);
    printf("Clientes Aprovados:           %d\n", total_aprovados);
    printf("Clientes Em Analise:          %d\n", total_analise);
    printf("Clientes Reprovados:          %d\n", total_reprovados);
    printf("==================================================\n");

}
