#include <stdio.h>
int estoque[5][5];
void inicial(int a,int p, int q){
	estoque[a][p] = q;
}
void add(int a,int p, int q){
	estoque[a][p] += q;
}
void sub(int a,int p, int q){
	if (estoque[a][p]>=q){
		estoque[a][p] -= q;
	}else{
		printf("Quantidade insuficiente de produto!");
	}
}
int main(){
	
	int armazem,produto,qtd,controle=-1,acao;
	for (armazem=0;armazem<5;armazem++){
		for (produto=0;produto<5;produto++){
			printf("Informe a qtd inicial do produto %d no armazem %d: ",produto,armazem);
			scanf("%d",&qtd);
			
			inicial(armazem,produto, qtd);
		}
	}
	
	while(controle != 0){
		//system("cls");
		printf("Informe que produto você deseja. ");
		scanf("%d",&produto);
		printf("Informe de que armazem ele sera movimentado. ");
		scanf("%d",&armazem);
		printf("Voce deseja (1)incluir ou (2)retirar? ");
		scanf("%d",&acao);
		printf("Qual quantidade sera movimentada? ");
		scanf("%d",&qtd);
		if (acao==1){
			add(armazem,produto, qtd);
		}if (acao==2){
			sub(armazem,produto, qtd);
		}
		printf("Movimentacao executada com sucesso!");
		
		printf("Deseja realizar mais alguma operacao? (0)NAO (1)SIM");
		scanf("%d",&controle);
	}
		
}
