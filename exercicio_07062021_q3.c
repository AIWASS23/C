#include <stdio.h>

void main(){
	FILE *arq,*arq2;
	int dia,mes,ano;
	arq = fopen("lista.txt","r");
	if (arq == NULL){
		printf("Nao foi possivel abrir o arquivo.");
	}
	arq2 = fopen("idades.txt","w");
	
	fscanf(arq,"%d %d %d",&dia,&mes,&ano);
	printf("Dia = %d\n",dia);
	printf("Mes = %d\n",mes);
	printf("Ano = %d\n",ano);
	printf("idade = %d\n\n",2021-ano);
	fprintf(arq2,"nome %d\n",2021-ano);
	
	fscanf(arq,"%d %d %d",&dia,&mes,&ano);
	printf("Dia = %d\n",dia);
	printf("Mes = %d\n",mes);
	printf("Ano = %d\n",ano);
	printf("idade = %d\n\n",2021-ano);
	fprintf(arq2,"%d\n",2021-ano);
		
	fscanf(arq,"%d %d %d",&dia,&mes,&ano);
	printf("Dia = %d\n",dia);
	printf("Mes = %d\n",mes);
	printf("Ano = %d\n",ano);
	printf("idade = %d\n\n",2021-ano);
	fprintf(arq2,"%d\n",2021-ano);
	
}
