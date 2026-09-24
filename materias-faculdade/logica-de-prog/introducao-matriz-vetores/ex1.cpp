#include <stdio.h>
#define TAM 5

main() {
	float notas[TAM], media, soma = 0;

	for(int c = 0; c < TAM; c++){
		printf("Digite a nota %d: ", c+1);
		scanf("%f", &notas[c]);
	}
	
	for(int c = 0; c < TAM; c++){
		soma += notas[c];
	}
	
	media = soma/TAM;
	printf("%2.f ", media);
}
