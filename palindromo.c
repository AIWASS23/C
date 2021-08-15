#include<math.h>
#include<stdio.h>
#include<string.h>

int main(){

int n1,n2,n3,n4,n5,numero,aux, inverter;

printf("Digite um numero");

scanf("%d",&numero);

n1 = numero / 10000;
aux = numero % 10000;
n2 = aux / 1000;
aux = aux % 1000;
n3 = aux / 100;
aux = aux % 100;
n4 = aux / 10;
n5 = aux % 10;

inverter = (n5 * 10000) + (n4 * 1000) + (n3 * 100) + (n2 * 10) + n1;

if (numero == inverter){
printf("O NUMERO E PALINDROMO\n");
}

else {
printf("O NUMERO NAO E PALINDROMO\n");
}

return 0;
}
