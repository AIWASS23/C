#include <stdio.h>

int main() {
	int i,aux; 
	int p=100;
	int vetor[6]={10,1,4,-1,-7,8};
	int soma=vetor[0]+vetor[1]+vetor[5];
	printf("resultado da soma = %d \n",soma);
	aux=vetor[3];
	vetor[3]=p;
	aux=p;
	for(i=0; i<=5; i++){
	    printf("%d\n",vetor[i]);
	}
	
	return 0;
}

