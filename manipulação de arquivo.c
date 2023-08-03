#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	FILE *arq;
	char texto[100];
	char texto1[100];
	char texto2[100];

	printf("Digite o texto!");
	gets(texto);

	arq = fopen("texto.txt", "w");
	fprintf(arq, "%s", texto1);
	fclose(arq);

	arq = fopen("texto.txt", "r");
	fscanf(arq, "%s", texto2);
	fclose(arq);
	
	arq = fopen("texto.txt", "r");
	fgets(texto2, 100, arq);
	fclose(arq);
	
}
