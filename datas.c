#include <stdio.h>

int main(void) {
	int data [2][2];
	int aux1,aux2,diferenca;

	printf("Informe o ano entre 1950 e 1996 \n");
	scanf("%d", &data[0][0]);
	   if(data[0][0] < 1950 || data[0][0] > 1996) {
	        printf("Ano invalido \n ");
	    }
	printf("Informe o mes \n");
	scanf("%d", &data[0][1]);
	   if(data[0][1] < 1 || data[0][1] > 12) {
	        printf("Mes invalido \n");
	    }
	printf("Informe o dia \n");
	scanf("%d", &data[0][2]);
	   if(data[0][2] < 1 || data[0][2] > 30) {
	       printf("Dia invalido \n");
	   }
	printf("Informe o ano entre 1950 e 1996 \n");
	scanf("%d", &data[1][0]);
	   if(data[1][0] < 1950 || data[1][0] > 1996) {
	        printf("Ano invalido \n ");
	    }
	printf("Informe o mes \n");
	scanf("%d", &data[1][1]);
	   if(data[1][1] < 1 || data[1][1] > 12) {
	        printf("Mes invalido \n");
	    }
	printf("Informe o dia \n");
	scanf("%d", &data[1][2]);
	   if(data[1][2] < 1 || data[1][2] > 30) {
	       printf("Dia invalido \n");
	   }
	aux1 = data[0][0] * 360;
	aux1 += data[0][1] * 30;
	aux1 += data[0][2];

	aux2 = data[1][0] * 360;
	aux2 += data[1][1] * 30;
	aux2 += data[1][2];

	if(aux1 > aux2) {
	    diferenca = aux1 - aux2;
	} else {
	    diferenca = aux2 - aux1;
	}

	data[2][0] = diferenca / 360;
	diferenca = diferenca - (data[2][0] * 360);

	data[2][1] = diferenca / 30;
	diferenca = diferenca - (data[2][1] * 30);

	data[2][2] = diferenca;

	printf("A diferenca = %d anos %d meses %d dias", data[2][0], data[2][1], data[2][2]);

	return 0;
}

