#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	FILE *arq;
	char texto[100];
	char letra;
	int i;
	
	printf("Escreva um texto");
	getc(texto);

	arq = fopen("teste.txt", "w");
	
	for(int i=0; i<strlen(texto); i++){
		putc(texto[i], arq);
	}
	fclose(arq);
	
	printf("\n\n LEITURA DO ARQUIVO \n\n");
	
	arq = fopen("teste.txt", "r");
	while((letra = getc(arq)) != EOF){
		printf("%c", letra);
	}
	fclose(arq);
}
