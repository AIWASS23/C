#include <stdio.h>

int main() {
    float lado;
    printf("Informe a medida do lado do quadrdo em Metros \n");
    scanf("%f", &lado);

    float area;
    area = lado * lado;
    printf("A area de quadrado em metros quadrados = %f \n", area);

    return 0;
}
