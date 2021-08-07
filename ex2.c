#include <stdio.h>

int main(){
	int hora[3][3];
	int aux1,aux2,diferenca;
	
	printf("Informe a hora:");
	scanf("%d",&hora[0][0]);
	printf("Informe os minutos:");
	scanf("%d",&hora[0][1]);
	printf("Informe os segundos:");
	scanf("%d",&hora[0][2]);
	
	printf("Informe a hora:");
	scanf("%d",&hora[1][0]);
	printf("Informe os minutos:");
	scanf("%d",&hora[1][1]);
	printf("Informe os segundos:");
	scanf("%d",&hora[1][2]);
	
	aux1 = hora[0][0]*60*60;
	aux1 += hora[0][1]*60;
	aux1 += hora[0][2];
	
	aux2 = hora[1][0]*60*60;
	aux2 += hora[1][1]*60;
	aux2 += hora[1][2];
	
	if (aux1>aux2){
		diferenca = aux1-aux2;
	}else{
		diferenca = aux2-aux1;
	}
	hora[2][0] = ((diferenca)/60)/60;
	
	diferenca = diferenca - (hora[2][0]*3600);
	
	hora[2][1] = diferenca/60;
	
	diferenca = diferenca - (hora[2][1] *60);
	
	hora[2][2] = diferenca;


	printf("A diferenca eh: %d:%d:%d",hora[2][0],hora[2][1],hora[2][2]);
}
