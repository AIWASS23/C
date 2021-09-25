#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.00000001

double **alocaMatriz(int l, int c){
	int i;
	double **m;
	
	m = malloc(sizeof(m) * l);
	if(m == NULL){
		return NULL;
	}
	for(int i = 0; i < l; i++){
		m[i] = malloc(sizeof(double) * c);
		if(m[i] == NULL){
			for(int j =0; j < i; j++){
				free(m[j]);
			}
			free(m);
			return NULL;
		}
	}
	return m;
}

void leMatriz(double **m, int l, int c){
	int i,j;
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("m[%d][%d] : ", i + 1, j + 1);
			scanf("%lf", &m[i][j]);
		}
	}
}
void imprimeMatriz(double **m, int l, int c){
	
	int i, j;
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("%10.4lf", m[i][j]);
		}
		printf("\n");
	}
	
int sretro( double **m, int n, double x[]){
	int i, j, tipo = 0;
	double *aux, soma;
	
	for(int i = n - 1; i >= 0; i--){
		soma = 0;
		for(int j = i + 1; j < n; j+:){
			soma = soma + m[i][j] * x[j];
		}
		if(m[i][i] == 0){
	   	if(m[i][n] == soma){
	   		x[i] = 0; 
	   		tipo = 1;
			}
			else{
				return 2;
			}
		}
		else{
			x[i] = (m[i][n] - soma) / m[i][i];
		}
   }
  return tipo;
}

void Gauss(double **m, int n){
	int i, j, k;
	double multi, *aux;
	
	for(int i = 0; i < n -1; i++){
		if(m[i][i] == 0){
			j = i + 1;
			while(j < n && m[i][i] == 0){
				j++;
			}
			if(j < n){
				aux = m[i];
				m[i] = m[j];
				m[j] = aux;
			}
		}
		if(m[i][i] != 0){
			for(int j = i + 1; j < n; j++){
				mult = -m[j][i] / m[i][i];
				m[j][i] = 0;
				for(int k = i + 1; k <= n; k++){
					m[j][k] = m[j][k] + mult * m[i][k];
				}
			}
		}
	}
}

int main(){
	
	int i, n, tipo;
	double **m, *x;
	
	printf(" quantidade de variaveis");
	scanf("%d", &n);
	
	m = alocaMatriz(n, n + 1);
	x = malloc(sizeof(double) * n);
	if (m == NULL && x == NULL){
		printf("Deu pau!! \n");
		return 1;
	}	
	leMatriz(m, n, n + 1);
   imprimeMatriz(m, n, n + 1);
	Gauss(m, n);
	printf("SL: TS: \n");
	imprimeMatriz(m, n, n + 1);
	tipo = sretro(m, n, x);
	
	if(tipo == 2){
		printf("SL incomparivel \n");
	}
	else{
		printf("SL %sdeterminado \n", tipo ? "in" : "");
		for(int i = 0; i < n; i++){
			printf("x[%d]: %10.4lf\n", i + 1, x[i]);
		}
	}
	return 0;	
}
