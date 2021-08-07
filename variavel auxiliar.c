#include <stdio.h>

void main() {
    int a = 3, b = 2, aux;
    aux = a;
    a = b;
    b = aux;

    printf("valor de a = %d \n valor de b = %d \n", a, b);


}
