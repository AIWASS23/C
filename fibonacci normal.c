#include <stdio.h>

float fibonacci(float n){
    float i, fibonacci1 = 1, fibonacci2 = 1, soma;
    for(i = 3; i <= n; i = i + 1){
        soma = fibonacci1 + fibonacci2;
        fibonacci1 = fibonacci2;
        fibonacci2 = soma;
    }
    return fibonacci2;
}
int main(void){
    float n;
    scanf("%f", &n);
    printf("%f \n", fibonacci(n));
    return 0;
}



