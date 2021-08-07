#include <stdio.h>

void main(){
	FILE *arq,*arq2;
	char c;
	arq = fopen("arq1.txt","r");
	if (arq == NULL){
		printf("Nao foi possivel abrir o arquivo.");
	}
	arq2 = fopen("arq2.txt","w");
	
	while( (c = getc(arq)) != EOF ){
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
			c = '*';
		}else{
			c = '_';
		}
		printf("%c",c);
		putc(c,arq2);
	}

}
