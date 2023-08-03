#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void clean_stdin(void);
void le_string(char *string);

int main(){

	FILE *arq;
	char caractere;
	char cadeia[30];


	arq = fopen("arq1", "w+");
	if(arq == NULL){
		printf("Erro");
	}
	else{
		printf("sucesso na abertura");
		printf("digite uma cadeia de caracteres");

		fgets(cadeia, 30, stdin);
		cadeia[strspn(cadeia, "\n");
	}
}

