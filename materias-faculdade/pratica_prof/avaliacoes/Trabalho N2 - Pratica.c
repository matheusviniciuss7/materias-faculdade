#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_ITENS 100
#define USUARIO_CORRETO "admin"
#define SENHA_CORRETA "1234"

typedef struct {
    char nome[100];
    char telefone[20];
    int cadastrado;
} Cliente;

typedef struct {
    char nome[100];
    char especie[30];
    char raca[50];
    int porte;
    int cadastrado;
} Pet;

typedef struct {
    char descricao[100];
    int quantidade;
    float valorUnitario;
    float valorTotal;
} ItemComprovante;

ItemComprovante carrinho[MAX_ITENS];
int totalItensCarrinho = 0;

int realizarLogin();
void menuCadastros(Cliente *cli, Pet *p);
void menuServicos(Pet *p);
void menuProdutos();
void exibirComprovante(char *funcionario, Cliente cli, Pet p);
void adicionarItemCarrinho(char *descricao, int qtd, float valorUnit);

float calcularBanho(int porte);
float calcularTosa(int opcaoTosa);
float calcularVeterinaria(int opcaoVet);

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
    char nomeFuncionario[50] = USUARIO_CORRETO;
    Cliente clienteAtivo = {"", "", 0};
    Pet petAtivo = {"", "", "", 0, 0};
    int opcao;

    printf("======================================\n");
    printf("    BEM-VINDO AO PETSHOP AMIGO FIEL   \n");
    printf("======================================\n");

    if (!realizarLogin()) {
        printf("\nNúmero máximo de tentativas atingido. Programa encerrado.\n");
        return 0;
    }

    do {
        printf("\n==============================\n");
        printf("      PETSHOP AMIGO FIEL      \n");
        printf("==============================\n");
        printf("  1 - Cadastros\n");
        printf("  2 - Serviços\n");
        printf("  3 - Produtos\n");
        printf("  4 - Comprovante final\n");
        printf("  0 - Sair\n");
        printf("==============================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                menuCadastros(&clienteAtivo, &petAtivo);
                break;
            case 2:
                if (!petAtivo.cadastrado) {
                    printf("\n[AVISO] Cadastre um cliente e um pet antes de lançar serviços!\n");
                } else {
                    menuServicos(&petAtivo);
                }
                break;
            case 3:
                if (!petAtivo.cadastrado) {
                    printf("\n[AVISO] Cadastre um cliente e um pet antes de lançar produtos!\n");
                } else {
                    menuProdutos();
                }
                break;
            case 4:
                exibirComprovante(nomeFuncionario, clienteAtivo, petAtivo);
                break;
            case 0:
                printf("\nEncerrando o sistema... Até logo!\n");
                break;
            default:
                printf("\n[ERRO] Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

int realizarLogin() {
    char usuario[50];
    char senha[50];
    int tentativas = 0;

    while (tentativas < 3) {
        printf("\n--- LOGIN DO FUNCIONÁRIO ---\n");
        printf("Usuário: ");
        scanf("%49s", usuario);
        printf("Senha: ");
        scanf("%49s", senha);

        if (strcmp(usuario, USUARIO_CORRETO) == 0 && strcmp(senha, SENHA_CORRETA) == 0) {
            printf("\nLogin realizado com sucesso!\n");
            return 1; 
        } else {
            tentativas++;
            printf("\n[ERRO] Usuário ou senha incorretos! Tentativas restantes: %d\n", 3 - tentativas);
        }
    }
    return 0;
}

void menuCadastros(Cliente *cli, Pet *p) {
    int opcao;
    do {
        printf("\n--------- CADASTROS ----------\n");
        printf("  1 - Cadastrar cliente\n");
        printf("  2 - Cadastrar pet\n");
        printf("  0 - Voltar\n");
        printf("------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\n--- Cadastrar Cliente ---\n");
                printf("Nome do cliente: ");
                fgets(cli->nome, sizeof(cli->nome), stdin);
                cli->nome[strcspn(cli->nome, "\n")] = 0; // Remover quebra de linha

                printf("Telefone: ");
                fgets(cli->telefone, sizeof(cli->telefone), stdin);
                cli->telefone[strcspn(cli->telefone, "\n")] = 0;

                cli->cadastrado = 1;
                printf("\nCliente cadastrado com sucesso!\n");
                break;

            case 2:
                if (!cli->cadastrado) {
                    printf("\n[AVISO] Cadastre um cliente primeiro antes de cadastrar o pet!\n");
                } else {
                    printf("\n--- Cadastrar Pet ---\n");
                    printf("Nome do pet: ");
                    fgets(p->nome, sizeof(p->nome), stdin);
                    p->nome[strcspn(p->nome, "\n")] = 0;

                    printf("Espécie (cão ou gato): ");
                    fgets(p->especie, sizeof(p->especie), stdin);
                    p->especie[strcspn(p->especie, "\n")] = 0;

                    printf("Raça: ");
                    fgets(p->raca, sizeof(p->raca), stdin);
                    p->raca[strcspn(p->raca, "\n")] = 0;

                    do {
                        printf("Porte (1 - Pequeno | 2 - Médio | 3 - Grande): ");
                        scanf("%d", &p->porte);
                        if (p->porte < 1 || p->porte > 3) {
                            printf("Opção de porte inválida! Escolha 1, 2 ou 3.\n");
                        }
                    } while (p->porte < 1 || p->porte > 3);

                    p->cadastrado = 1;
                    printf("\nPet cadastrado com sucesso!\n");
                }
                break;

            case 0:
                break;

            default:
                printf("\n[ERRO] Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

float calcularBanho(int porte) {
    switch (porte) {
        case 1: return 40.00f; // Pequeno
        case 2: return 55.00f; // Médio
        case 3: return 70.00f; // Grande
        default: return 0.00f;
    }
}

float calcularTosa(int opcaoTosa) {
    switch (opcaoTosa) {
        case 1: return 30.00f; // Higiênica
        case 2: return 50.00f; // Completa
        case 3: return 65.00f; // Na tesoura
        default: return 0.00f;
    }
}

float calcularVeterinaria(int opcaoVet) {
    switch (opcaoVet) {
        case 1: return 120.00f; // Consulta
        case 2: return 80.00f;  // Vacina
        case 3: return 150.00f; // Exame
        default: return 0.00f;
    }
}

void menuServicos(Pet *p) {
    int opcao, subOpcao;
    float valor;

    do {
        printf("\n---------- SERVIÇOS ----------\n");
        printf("  1 - Banho\n");
        printf("  2 - Tosa\n");
        printf("  3 - Veterinária\n");
        printf("  0 - Voltar\n");
        printf("------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                valor = calcularBanho(p->porte);
                printf("\nServiço de Banho adicionado! Valor: R$ %.2f\n", valor);
                adicionarItemCarrinho("Serviço - Banho", 1, valor);
                break;

            case 2:
                printf("\n--- OPÇÕES DE TOSA ---\n");
                printf("  1 - Tosa Higiênica (R$ 30,00)\n");
                printf("  2 - Tosa Completa  (R$ 50,00)\n");
                printf("  3 - Tosa na Tesoura(R$ 65,00)\n");
                printf("Escolha o tipo de tosa: ");
                scanf("%d", &subOpcao);

                if (subOpcao >= 1 && subOpcao <= 3) {
                    valor = calcularTosa(subOpcao);
                    char desc[50];
                    if (subOpcao == 1) strcpy(desc, "Serviço - Tosa Higiênica");
                    else if (subOpcao == 2) strcpy(desc, "Serviço - Tosa Completa");
                    else strcpy(desc, "Serviço - Tosa na Tesoura");

                    printf("Serviço adicionado! Valor: R$ %.2f\n", valor);
                    adicionarItemCarrinho(desc, 1, valor);
                } else {
                    printf("\n[ERRO] Opção de tosa inválida.\n");
                }
                break;

            case 3:
                printf("\n--- VETERINÁRIA ---\n");
                printf("  1 - Consulta (R$ 120,00)\n");
                printf("  2 - Vacina   (R$ 80,00)\n");
                printf("  3 - Exame    (R$ 150,00)\n");
                printf("Escolha a opção: ");
                scanf("%d", &subOpcao);

                if (subOpcao >= 1 && subOpcao <= 3) {
                    valor = calcularVeterinaria(subOpcao);
                    char desc[50];
                    if (subOpcao == 1) strcpy(desc, "Vet - Consulta");
                    else if (subOpcao == 2) strcpy(desc, "Vet - Vacina");
                    else strcpy(desc, "Vet - Exame");

                    printf("Serviço veterinário adicionado! Valor: R$ %.2f\n", valor);
                    adicionarItemCarrinho(desc, 1, valor);
                } else {
                    printf("\n[ERRO] Opção veterinária inválida.\n");
                }
                break;

            case 0:
                break;

            default:
                printf("\n[ERRO] Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

void menuProdutos() {
    int opcaoCat, prodOpcao, qtd;

    char alimentosNomes[3][50] = {"Ração cão 10kg", "Ração gato 3kg", "Petisco"};
    float alimentosPrecos[3] = {120.00f, 65.00f, 15.00f};

    char acessoriosNomes[3][50] = {"Coleira Guia", "Brinquedo Osso", "Caminha Pet"};
    float acessoriosPrecos[3] = {45.00f, 25.00f, 110.00f};

    char higieneNomes[3][50] = {"Shampoo Pet", "Escova Pêlos", "Tapete Higiênico"};
    float higienePrecos[3] = {28.00f, 20.00f, 55.00f};

    do {
        printf("\n---------- PRODUTOS ----------\n");
        printf("  1 - Alimentos\n");
        printf("  2 - Acessórios\n");
        printf("  3 - Higiene\n");
        printf("  0 - Voltar\n");
        printf("------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoCat);

        if (opcaoCat >= 1 && opcaoCat <= 3) {
            printf("\n");
            if (opcaoCat == 1) {
                printf("--------- ALIMENTOS ----------\n");
                for (int i = 0; i < 3; i++) {
                    printf("  %d - %-20s R$ %6.2f\n", i + 1, alimentosNomes[i], alimentosPrecos[i]);
                }
            } else if (opcaoCat == 2) {
                printf("--------- ACESSÓRIOS ---------\n");
                for (int i = 0; i < 3; i++) {
                    printf("  %d - %-20s R$ %6.2f\n", i + 1, acessoriosNomes[i], acessoriosPrecos[i]);
                }
            } else if (opcaoCat == 3) {
                printf("---------- HIGIENE -----------\n");
                for (int i = 0; i < 3; i++) {
                    printf("  %d - %-20s R$ %6.2f\n", i + 1, higieneNomes[i], higienePrecos[i]);
                }
            }
            printf("  0 - Voltar\n");

            printf("Produto: ");
            scanf("%d", &prodOpcao);

            if (prodOpcao >= 1 && prodOpcao <= 3) {
                printf("Quantidade: ");
                scanf("%d", &qtd);

                if (qtd > 0) {
                    int idx = prodOpcao - 1;
                    if (opcaoCat == 1) {
                        adicionarItemCarrinho(alimentosNomes[idx], qtd, alimentosPrecos[idx]);
                    } else if (opcaoCat == 2) {
                        adicionarItemCarrinho(acessoriosNomes[idx], qtd, acessoriosPrecos[idx]);
                    } else if (opcaoCat == 3) {
                        adicionarItemCarrinho(higieneNomes[idx], qtd, higienePrecos[idx]);
                    }
                    printf("\nProduto adicionado com sucesso!\n");
                } else {
                    printf("\n[ERRO] Quantidade deve ser maior que zero.\n");
                }
            } else if (prodOpcao != 0) {
                printf("\n[ERRO] Produto inválido.\n");
            }
        } else if (opcaoCat != 0) {
            printf("\n[ERRO] Opção inválida! Tente novamente.\n");
        }
    } while (opcaoCat != 0);
}

void adicionarItemCarrinho(char *descricao, int qtd, float valorUnit) {
    if (totalItensCarrinho < MAX_ITENS) {
        strcpy(carrinho[totalItensCarrinho].descricao, descricao);
        carrinho[totalItensCarrinho].quantidade = qtd;
        carrinho[totalItensCarrinho].valorUnitario = valorUnit;
        carrinho[totalItensCarrinho].valorTotal = qtd * valorUnit;
        totalItensCarrinho++;
    } else {
        printf("\n[AVISO] Capacidade máxima de itens no comprovante atingida!\n");
    }
}

void exibirComprovante(char *funcionario, Cliente cli, Pet p) {
    float totalAtendimento = 0.0f;

    printf("\n======================================================\n");
    printf("               COMPROVANTE DE ATENDIMENTO             \n");
    printf("                  PETSHOP AMIGO FIEL                  \n");
    printf("======================================================\n");
    printf("Funcionário: %s\n", funcionario);
    
    if (cli.cadastrado) {
        printf("Cliente: %s | Tel: %s\n", cli.nome, cli.telefone);
    } else {
        printf("Cliente: Não informado\n");
    }

    if (p.cadastrado) {
        char porteTexto[15];
        if (p.porte == 1) strcpy(porteTexto, "Pequeno");
        else if (p.porte == 2) strcpy(porteTexto, "Médio");
        else strcpy(porteTexto, "Grande");

        printf("Pet: %s (%s, %s, Porte: %s)\n", p.nome, p.especie, p.raca, porteTexto);
    } else {
        printf("Pet: Não informado\n");
    }

    printf("------------------------------------------------------\n");
    printf("%-25s %-5s %-12s %-10s\n", "Item", "Qtd", "Val. Unit", "Total");
    printf("------------------------------------------------------\n");

    if (totalItensCarrinho == 0) {
        printf("Nenhum serviço ou produto registrado neste atendimento.\n");
    } else {
        for (int i = 0; i < totalItensCarrinho; i++) {
            printf("%-25s %-5d R$ %-9.2f R$ %-8.2f\n", 
                   carrinho[i].descricao, 
                   carrinho[i].quantidade, 
                   carrinho[i].valorUnitario, 
                   carrinho[i].valorTotal);
            totalAtendimento += carrinho[i].valorTotal;
        }
    }

    printf("======================================================\n");
    printf("VALOR TOTAL DO ATENDIMENTO: R$ %.2f\n", totalAtendimento);
    printf("======================================================\n\n");
}
