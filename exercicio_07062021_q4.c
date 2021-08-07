#include <stdio.h>

void main(){
	FILE *arq,*arq2;
	int conta=0;
	char c;
	arq = fopen("idades.txt","r");
	if (arq == NULL){
		printf("Nao foi possivel abrir o arquivo.");
	}
	
	while( (c = getc(arq)) != EOF ){
		if (c == '\n'){
			conta++;
		}
	}
	printf("Quantidade de linhas = %d",conta);
}
