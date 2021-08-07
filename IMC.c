#include <stdio.h>

int main() {
    float peso, altura;
    printf("Informe seu peso em Quilogramas \n");
    scanf("%f", &peso);
    printf("Informe sua altura em Metros \n");
    scanf("%f", &altura);

    float IMC;
    IMC = peso / (altura * altura);
    printf("O resultado do seu IMC = %f \n", IMC);
    return 0;

}
