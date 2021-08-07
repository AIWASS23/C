#include <stdio.h>

int main(){
	FILE *arq;
	char c;
	int conta[5]={0,0,0,0,0};
	arq = fopen("arq.txt","r");
	if (arq == NULL){
		printf("Nao foi possivel abrir o arquivo.");
	}
	
	while( (c = getc(arq)) != EOF ){
		printf("%c",c);
		if (c == 'a'){
			conta[0]++;
		}else if (c == 'e'){
			conta[1]++;
		}else if (c == 'i'){
			conta[2]++;
		}else if (c == 'o'){
			conta[3]++;
		}else if (c == 'u'){
			conta[4]++;
		}
		
	}
	printf("\n\n");
	printf("A letra a, aparece %d vezes.\n",conta[0]);
	printf("A letra e, aparece %d vezes.\n",conta[1]);
	printf("A letra i, aparece %d vezes.\n",conta[2]);
	printf("A letra o, aparece %d vezes.\n",conta[3]);
	printf("A letra u, aparece %d vezes.\n",conta[4]);
}
