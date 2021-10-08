#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(){
    int numeros[TAM];
    int i, aux, contador;

    printf("Entre com dez números para preencher o vetor, e pressione enter após digitar cada um:\n");

    for (i = 0; i < TAM; i++){
        scanf("%d", &numeros[i]);
    }

    printf("Ordem atual dos itens no vetor:\n");

    for (i = 0; i < TAM; i++) {
        printf("%d", numeros[i]);
    }

    for (int contador = 1; contador < TAM; contador++){
        for (int i = 0; i < TAM - 1; i++){
            if (numeros[i] > numeros[i + 1]){
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
            }
        }
    }
    printf("\nElementos do vetor em ordem crescente:\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d", numeros[i]);
    }
    printf("\n");

    return 0;
}