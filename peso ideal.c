#include <stdio.h>

int main() {
    float altura;
    printf("Digite o valor correspondente a sua altura em metros \n");
    scanf("%f", &altura);

    float peso;
    peso = (72.7 * altura) - 58;
    printf("Seu peso ideal = %f \n", peso);
    return 0;
}
