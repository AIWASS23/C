#include <stdio.h>

int main(){
	int data [3][3];
	double aux1,aux2,diferenca1,diferenca2,diferenca3;
	
	printf("Informe o dia \n");
	scanf("%d",&data[0][0]);
	   if(data[0][0]<1||data[0][0]>30){
	        printf("Dia invalido \n ");
	   }
	printf("Informe o mes \n");
	scanf("%d",&data[0][1]);
	   if(data[0][1]<1||data[0][1]>12){
	        printf("Mes invalido \n");
	   }
	printf("Informe o ano entre 1950 e 1996 \n");
	scanf("%d",&data[0][2]);
	   if(data[0][2]<1950||data[0][2]>1996){
	   	printf("Ano invalido \n");
	   }
	printf("Informe o dia \n");
	scanf("%d",&data[1][0]);
	   if(data[1][0]<1||data[1][0]>30){
	        printf("Dia invalido \n ");
	   }
	printf("Informe o mes \n");
	scanf("%d",&data[1][1]);
	   if(data[1][1]<1||data[1][1]>12){
	        printf("Mes invalido \n");
	   }
	printf("Informe o ano entre 1950 e 1996\n");
	scanf("%d",&data[1][2]);
	   if(data[1][2]<1950||data[1][2]>1996){
	   	    printf("Ano invalido \n");
	   }

	aux1=data[0][2]*360;
	aux1=aux1+(data[0][1]*30);
	aux1=aux1+data[0][0];
	
	aux2=data[1][2]*360;
	aux2=aux2+(data[1][1]*30);
	aux2=aux2+data[1][0];
	
	if(aux1>aux2){
	    diferenca1=aux1-aux2;
	} else{
	    diferenca1=aux2-aux1;
	}
	
	data[2][2]=(diferenca1/360);
	diferenca2=diferenca1-(data[2][2]*360);
	
	data[2][1]=diferenca2/30;
	diferenca3=diferenca2-(data[2][1]*30);
	
	data[2][0]=diferenca3;
	
	printf("A diferenca = %d anos %d meses %d dias \n",data[2][2],data[2][1],data[2][0]);
	    
	return 0;
}

