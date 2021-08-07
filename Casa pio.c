#include <stdio.h>

int main(){
	double valor_total,montante;
	int opcao,parcelas;
	char repete='s';
	
	while(repete=='s'){
		printf("Informe o valor da compra: ");
		scanf("%lf",&valor_total);
		
		printf("\n");
		printf("1) Pagamento a vista \n");
		printf("2) Parcelado 2x \n");
		if (valor_total>100){
			printf("3) 3 a 10, com juros 3 a.m.\n");
		}
		printf("\n");
		printf("Informe sua opcao: ");
		scanf("%d",&opcao);
		switch (opcao){ 
		case 1: 
			printf("Valor devido: %.2lf",valor_total*0.9);
			break;
		case 2:
			printf("Parcela 1: %.2lf\n",valor_total/2);
			printf("Parcela 2: %.2lf\n",valor_total/2);
			printf("-------------------\n");
			printf("Total: %.2lf\n",valor_total);
			break;
		case 3:
			printf("Informe a quant de parcelas (3 a 10): ");
			scanf("%d",&parcelas);
			montante = valor_total*0.03*parcelas + valor_total;
			
			for(int i=1;i<=parcelas;i++){
				printf("Valor da Parcela %d: %.2lf\n",i,montante/parcelas);
			}
			printf("-------------------\n");
			printf("Total: %.2lf\n",montante);
		break;
		default:
			printf("opção invalida!");
		break;
		}
		printf("\n");
		printf("Deseja atender outro cliente (n) nao (s) sim: ");
		scanf("%c",&repete);
	}
}
