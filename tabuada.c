#include <stdio.h>

int main() {
    int i, n, j, resultado;
    printf ("digite um numero entre 1 e 10 para calcular sua tabuada \n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        for (j = 1; j <= 10; j++){
            resultado = i * j;
            printf("tabuada de %d \n", n);
            printf("%d x %d = %d \n", n, j, resultado);
        }
    }
}




