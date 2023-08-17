#include <stdio.h> // direto

void main(){
   int fatorial = 1;
   int num;
   printf("digite um numero a ser calculado o fatorial ");
   scanf("%d", &num);
   
   for(int i = num; i > 1; i--){
   fatorial *= i; // fatorial = fatorial * i;
   } 
   printf("resultado do fatorial = %d \n", fatorial);
}


#include <stdio.h> // com função

int fatorial(int num){
   int resultado = 1;
   for(int i = num; i > 1; i--){
   resultado *= i; // resultado = resultado * i;
   } 
   return resultado;
}

void main(){

   int num;
   printf("digite o valor a ser calculado o fatorial");
   scanf("%d", &num);
   printf("resultado = %d", fatorial(num));
}


#include <stdio.h> // recursividade

int fatorial(int num){
   if(n == 1){
     return 1;
   }else{
    return num * fatorial(n - 1);
   }

void main(){
   int num;
   printf("digite o valor a ser calculado o fatorial");
   scanf("%d", &num);
   printf("resultado = %d", fatorial(num));
}




