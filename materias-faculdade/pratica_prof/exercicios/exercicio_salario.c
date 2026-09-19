#include <stdio.h>

main() {
	char nome[10];
	float sal, vt, va, salfinal;
	
	printf("Qual o nome do funcionario(a)?");
	scanf("%s", nome);
	
	printf("Qual o salario do %s?");
	scanf("%f", sal);
	
	printf("Qual o valor do vale transporte?");
	scanf("%f", vt);
	
	printf("Qual o valor do vale alimentacao?");
	scanf("%f", va);

	salfinal = sal + va +vt;

	printf("O salario final sera de %f reais!", salfinal);
	
}
