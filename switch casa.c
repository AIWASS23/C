#include <stdio.h>

void main() {
    int x;
    printf("MENU DO DIA:\n");
    printf("1 PIZZA \n");
    printf("2 MACARRONADA \n");
    printf("3 RISOTO \n");
    printf("4 LASANHA \n");
    printf("DIGITE O NUMERO CORRESPONDENTE AO PRATO DE SUA ESCOLHA \n");
    scanf("%d", &x);
    if (x < 1 || x > 4) {
        printf("MENU INVALIDO \n");
    }
    switch (x) {
        case 1:
            printf("OBRIGADO POR ESCOLHER NOSSO PRATO: PIZZA \n");
            break;
        case 2:
            printf("OBRIGADO POR ESCOLHER NOSSO PRATO: PIZZA \n");
            break;
        case 3:
            printf("OBRIGADO POR ESCOLHAR NOSSO PRATO: RISOTO \n");
            break;
        case 4:
            printf("OBRIGADO POR ESCOLHAR NOSSO PRATO: LASANHA \n");
            break;
        default:
            printf("OBRIGADO PELA PREFERENCIA \n");
    }
}
