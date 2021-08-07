#include <stdio.h>

int main(){
	double peso, peso_total=0;
	int conta=0;
	double maior,menor;

	while(peso != 0){
		printf("Informe o peso: ");
		scanf("%lf",&peso);
		if (peso == 0){ break; }
		if (peso<0){
			printf("Valor invalido!");
		}else{
			conta++;
			peso_total += peso;
			if (conta==1){ 
				menor = peso; 
				maior = peso; 
			}else if (peso>maior){ maior = peso; }
			else if (peso<menor){ menor = peso; }
		}
		
	}
	
	printf("Total de melancias %d\n",conta);
	printf("Peso das melancias %lf\n",peso_total);
	printf("Peso medio %lf\n",peso_total/conta);
	printf("Maior peso %lf\n",maior);
	printf("Menor peso %lf\n",menor);
}
