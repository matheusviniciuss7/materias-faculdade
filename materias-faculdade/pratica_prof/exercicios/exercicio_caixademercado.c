#include <stdio.h>
#include <stdlib.h>

main() {
	char fun[10], prod1[15], prod2[15], prod3[15], prod4[15], prod5[15];
	int matricula;
	float produto1, produto2, produto3, produto4, produto5;
	float quant1, quant2, quant3, quant4, quant5;
	float soma1, soma2, soma3, soma4, soma5, vtotal;
	float desconto, vtotalcomdesconto;
	
	printf("Digite o nome do funcionario(a): ");
	scanf("%s", &fun);
	
	printf("Digite a matricula do %s: ", fun);
	scanf("%d", &matricula);
	
	printf("Digite o nome do primeiro produto:" );
	scanf("%s", &prod1);
	
	printf("Digite o preco do primeiro produto:" );
	scanf("%f", &produto1);
	
	printf("Digite a quantidade do primeiro produto:" );
	scanf("%f", &quant1);
	
	printf("Digite o nome do segundo produto:" );
	scanf("%s", &prod2);
	
	printf("Digite o preco do segundo produto:" );
	scanf("%f", &produto2);
	
	printf("Digite a quantidade do segundo produto:" );
	scanf("%f", &quant2);		
	
	printf("Digite o nome do terceiro produto:" );
	scanf("%s", &prod3);
	
	printf("Digite o preco do terceiro produto:" );
	scanf("%f", &produto3);
	
	printf("Digite a quantidade do terceiro produto:" );
	scanf("%f", &quant3);
	
	printf("Digite o nome do quarto produto:" );
	scanf("%s", &prod4);
	
	printf("Digite o preco do quarto produto:" );
	scanf("%f", &produto4);
	
	printf("Digite a quantidade do quarto produto:" );
	scanf("%f", &quant4);
	
	printf("Digite o nome do quinto produto:" );
	scanf("%s", &prod5);
	
	printf("Digite o preco do quinto produto:" );
	scanf("%f", &produto5);
	
	printf("Digite a quantidade do quinto produto:" );
	scanf("%f", &quant5);
	
	soma1 = produto1 * quant1;
	soma2 = produto2 * quant2;
	soma3 = produto3 * quant3;
	soma4 = produto4 * quant4;
	soma5 = produto5 * quant5;
	
 	vtotal = soma1 + soma2 + soma3 + soma4 + soma5;
 	desconto = vtotal * 0.05;
 	vtotalcomdesconto = vtotal - desconto; 
 	
 	system("cls");
 	
 	printf("%s / %d\n", fun, matricula);
 	printf("-------------------------------------------------------\n");
 	printf("NOME     PRECO    QUANTIDADE\n");
	printf("%s      %.2f      %2.f      \n", prod1, produto1, quant1);  
 	printf("%s      %.2f      %2.f      \n", prod2, produto2, quant2);
 	printf("%s      %.2f      %2.f      \n", prod3, produto3, quant3);
 	printf("%s      %.2f      %2.f      \n", prod4, produto4, quant4);
 	printf("%s      %.2f      %2.f      \n", prod5, produto5, quant5);
 	printf("O valor total fica %2.f \n", vtotal);
 	printf("Com 5%% de desconto o valor reduz %.2f ficando o valor total de %2.f", desconto, vtotalcomdesconto);
 		
}
