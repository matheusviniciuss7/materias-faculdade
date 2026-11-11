#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_ITENS 100
#define USUARIO_CORRETO "KOVALSKI"
#define SENHA_CORRETA "KOVALSKI"

char cartDesc[MAX_ITENS][50];
int cartQtd[MAX_ITENS];
float cartUnit[MAX_ITENS], cartTotal[MAX_ITENS];
int totalItens = 0;

int realizarLogin();
void adicionarItem(const char *desc, int qtd, float valor);
float calcularBanho(int porte);
float calcularTosa(int opcaoTosa);
float calcularVeterinaria(int opcaoVet);
void exibirComprovante(char *cli, char *tel, int cliOk, char *pet, char *esp, char *raca, int porte, int petOk);

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
    if (!realizarLogin()) {
        printf("\nNumero maximo de tentativas atingido. Encerrando.\n");
        return 0;
    }

    char cliNome[50] = "", cliTel[20] = "";
    char petNome[50] = "", petEsp[30] = "", petRaca[30] = "";
    int petPorte = 0, cliCad = 0, petCad = 0;

    char prodAlim[3][30] = {"Racao Cao 10kg", "Racao Gato 3kg", "Petisco"};
    float precoAlim[3]   = {120.0f, 65.0f, 15.0f};

    char prodAces[3][30] = {"Coleira Guia", "Brinquedo Osso", "Caminha Pet"};
    float precoAces[3]   = {45.0f, 25.0f, 110.0f};

    char prodHig[3][30]  = {"Shampoo Pet", "Escova Pelos", "Tapete Higienico"};
    float precoHig[3]    = {28.0f, 20.0f, 55.0f};

    int opPrincipal, opSub, subTipo, qtd;

    do {
        printf("\n==============================\n");
        printf("      PETSHOP KOVALSKI      \n");
        printf("==============================\n");
        printf("  1 - Cadastros\n");
        printf("  2 - Servicos\n");
        printf("  3 - Produtos\n");
        printf("  4 - Comprovante final\n");
        printf("  0 - Sair\n");
        printf("==============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opPrincipal);

        switch (opPrincipal) {
            case 1:
                do {
                    printf("\n--------- CADASTROS ----------\n");
                    printf("  1 - Cadastrar cliente\n");
                    printf("  2 - Cadastrar pet\n");
                    printf("  0 - Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &opSub);

                    if (opSub == 1) {
                        printf("\nNome do cliente: ");
                        scanf(" %[^\n]", cliNome);
                        printf("Telefone: ");
                        scanf(" %[^\n]", cliTel);
                        cliCad = 1;
                        printf("-> Cliente cadastrado com sucesso!\n");
                    } else if (opSub == 2) {
                        if (!cliCad) {
                            printf("\n[AVISO] Cadastre o cliente primeiro!\n");
                        } else {
                            printf("\nNome do pet: ");
                            scanf(" %[^\n]", petNome);
                            printf("Especie (cao ou gato): ");
                            scanf(" %[^\n]", petEsp);
                            printf("Raca: ");
                            scanf(" %[^\n]", petRaca);
                            do {
                                printf("Porte (1-Pequeno | 2-Medio | 3-Grande): ");
                                scanf("%d", &petPorte);
                            } while (petPorte < 1 || petPorte > 3);
                            petCad = 1;
                            printf("-> Pet cadastrado com sucesso!\n");
                        }
                    }
                } while (opSub != 0);
                break;

            case 2:
                if (!petCad) {
                    printf("\n[AVISO] Cadastre um cliente e pet antes dos servicos!\n");
                    break;
                }
                do {
                    printf("\n---------- SERVICOS ----------\n");
                    printf("  1 - Banho\n");
                    printf("  2 - Tosa\n");
                    printf("  3 - Veterinaria\n");
                    printf("  0 - Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &opSub);

                    if (opSub == 1) {
                        float v = calcularBanho(petPorte);
                        adicionarItem("Servico - Banho", 1, v);
                    } else if (opSub == 2) {
                        printf("\n1 - Tosa Higienica  (R$ 30,00)\n");
                        printf("2 - Tosa Completa    (R$ 50,00)\n");
                        printf("3 - Tosa na Tesoura  (R$ 65,00)\n");
                        printf("Opcao: ");
                        scanf("%d", &subTipo);

                        float v = calcularTosa(subTipo);
                        if (v > 0) {
                            char *nomeTosa[] = {"", "Tosa Higienica", "Tosa Completa", "Tosa Tesoura"};
                            adicionarItem(nomeTosa[subTipo], 1, v);
                        } else {
                            printf("[!] Opcao invalida.\n");
                        }
                    } else if (opSub == 3) {
                        printf("\n1 - Consulta (R$ 120,00)\n");
                        printf("2 - Vacina   (R$  80,00)\n");
                        printf("3 - Exame    (R$ 150,00)\n");
                        printf("Opcao: ");
                        scanf("%d", &subTipo);

                        float v = calcularVeterinaria(subTipo);
                        if (v > 0) {
                            char *nomeVet[] = {"", "Vet - Consulta", "Vet - Vacina", "Vet - Exame"};
                            adicionarItem(nomeVet[subTipo], 1, v);
                        } else {
                            printf("[!] Opcao invalida.\n");
                        }
                    }
                } while (opSub != 0);
                break;

            case 3:
                if (!petCad) {
                    printf("\n[AVISO] Cadastre um cliente e pet antes dos produtos!\n");
                    break;
                }
                do {
                    printf("\n---------- PRODUTOS ----------\n");
                    printf("  1 - Alimentos\n");
                    printf("  2 - Acessorios\n");
                    printf("  3 - Higiene\n");
                    printf("  0 - Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &opSub);

                    if (opSub >= 1 && opSub <= 3) {
                        char (*nomes)[30] = (opSub == 1) ? prodAlim : (opSub == 2 ? prodAces : prodHig);
                        float *precos     = (opSub == 1) ? precoAlim : (opSub == 2 ? precoAces : precoHig);

                        printf("\n--- ITENS ---\n");
                        for (int i = 0; i < 3; i++) {
                            printf("  %d - %-18s R$ %6.2f\n", i + 1, nomes[i], precos[i]);
                        }
                        printf("  0 - Voltar\n");
                        printf("Produto: ");
                        scanf("%d", &subTipo);

                        if (subTipo >= 1 && subTipo <= 3) {
                            printf("Quantidade: ");
                            scanf("%d", &qtd);
                            if (qtd > 0) {
                                adicionarItem(nomes[subTipo - 1], qtd, precos[subTipo - 1]);
                            } else {
                                printf("[!] Quantidade invalida.\n");
                            }
                        }
                    }
                } while (opSub != 0);
                break;

            case 4:
                exibirComprovante(cliNome, cliTel, cliCad, petNome, petEsp, petRaca, petPorte, petCad);
                break;

            case 0:
                printf("\nEncerrando sistema... Ate logo!\n");
                break;

            default:
                printf("\n[ERRO] Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opPrincipal != 0);

    return 0;
}

int realizarLogin() {
    char user[30], pass[30];
    int tentativas = 0;
    while (tentativas < 3) {
        printf("\n--- LOGIN DO FUNCIONARIO ---\n");
        printf("Usuario: ");
        scanf("%29s", user);
        printf("Senha: ");
        scanf("%29s", pass);

        if (strcmp(user, USUARIO_CORRETO) == 0 && strcmp(pass, SENHA_CORRETA) == 0) {
            printf("\nLogin realizado com sucesso!\n");
            return 1;
        }
        tentativas++;
        printf("[ERRO] Dados incorretos! Restam: %d\n", 3 - tentativas);
    }
    return 0;
}

void adicionarItem(const char *desc, int qtd, float valor) {
    if (totalItens < MAX_ITENS) {
        strcpy(cartDesc[totalItens], desc);
        cartQtd[totalItens] = qtd;
        cartUnit[totalItens] = valor;
        cartTotal[totalItens] = qtd * valor;
        totalItens++;
        printf("-> Adicionado ao carrinho! (R$ %.2f)\n", qtd * valor);
    } else {
        printf("\n[AVISO] Limite maximo do carrinho atingido!\n");
    }
}

float calcularBanho(int porte) {
    if (porte == 1) return 40.00f;
    if (porte == 2) return 55.00f;
    if (porte == 3) return 70.00f;
    return 0.00f;
}

float calcularTosa(int opcaoTosa) {
    if (opcaoTosa == 1) return 30.00f;
    if (opcaoTosa == 2) return 50.00f;
    if (opcaoTosa == 3) return 65.00f;
    return 0.00f;
}

float calcularVeterinaria(int opcaoVet) {
    if (opcaoVet == 1) return 120.00f;
    if (opcaoVet == 2) return 80.00f;
    if (opcaoVet == 3) return 150.00f;
    return 0.00f;
}

void exibirComprovante(char *cli, char *tel, int cliOk, char *pet, char *esp, char *raca, int porte, int petOk) {
    float totalAtendimento = 0.0f;
    char *porteTxt[] = {"-", "Pequeno", "Medio", "Grande"};

    printf("\n======================================================\n");
    printf("             COMPROVANTE DE ATENDIMENTO               \n");
    printf("                  PETSHOP KOVALSKI                  \n");
    printf("======================================================\n");
    printf("Funcionario: %s\n", USUARIO_CORRETO);
    printf("Cliente:     %s | Tel: %s\n", cliOk ? cli : "N/I", cliOk ? tel : "-");
    printf("Pet:         %s (%s, %s, Porte: %s)\n", 
           petOk ? pet : "N/I", petOk ? esp : "-", petOk ? raca : "-", petOk ? porteTxt[porte] : "-");
    printf("------------------------------------------------------\n");
    printf("%-24s %-4s %-10s %-10s\n", "Item", "Qtd", "Unit", "Total");
    printf("------------------------------------------------------\n");

    if (totalItens == 0) {
        printf("Nenhum item registrado neste atendimento.\n");
    } else {
        for (int i = 0; i < totalItens; i++) {
            printf("%-24s %-4d R$ %-7.2f R$ %-7.2f\n",
                   cartDesc[i], cartQtd[i], cartUnit[i], cartTotal[i]);
            totalAtendimento += cartTotal[i];
        }
    }

    printf("======================================================\n");
    printf("VALOR TOTAL: R$ %.2f\n", totalAtendimento);
    printf("======================================================\n");
}
