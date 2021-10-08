#include <stdio.h>
#define MAX 20

int main (){
    int cpf[MAX];
    int i, soma, resto, digito = 0;
    int digitoverificador;
    int n = 11;
    int interno[MAX];
    
    for(int i = 0; i < 11; i++){
        interno[i] = 0;
    }
    for(int i = 0; i < 11; i++){
        cpf[i] = 0;
    }

    printf("Digite o numero do CPF, sem pontos ou tracos: ");

    for(int i = 0; i < 11; i++){
        scanf("%d", &cpf[i]);
    }

    for(int i = 0;i < 9;i++){
        n = n - 1;
        interno[i] = n * cpf[i];
    }
    for(int i = 0;i < 9; i++){
        soma+=interno[i];
    }
    resto = soma%11;
    digito = 11-resto;

    if(resto < 2)
        {digitoverificador = 0;}

    else
        {digitoverificador = digito;}

    if(digitoverificador != cpf[9]){
        printf("\n * CPF invalido *");
    }

    n = 12;

    for(int i = 0;i < 9;i++){
        n = n - 1;
        interno[i] = n * cpf[i];
    }
    for(int i = 0;i < 9;i++){
        soma+=interno[i];
    }
    resto = soma%11;
    digito = 11 - resto;

    if(resto < 2)
        {digitoverificador = 0;}

    else
        {digitoverificador = digito;}

    if(digitoverificador != cpf[10]){
        printf("\n * CPF invalido **");
    }
    else
        {printf("\n * CPF valido *");}
    return 0;
}
