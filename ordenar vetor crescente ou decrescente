#include <stdio.h>

void main() {
   int numero;
   printf("Escolha a quantidade de numeros a ordenar \n");
   scanf("%d", &numero);

   int vetor[numero];
   int aux;
   for(j = 0; j <= numero; j++) {
       printf("Informe um numero \n");
       scanf("%d", &vetor[j]);
   }

   for(j = 0; j < (numero - 1); j++) {
      for(i = 0; i < (numero - 1); i++) {
          if(vetor[i] < vetor[i + 1]) // crescente
          if(vetor[i] > vetor[i + 1]) // decrescente {
             aux = vetor[i];
             vetor[i] = vetor[i + 1];
             vetor[i + 1] = aux;
          }
      }
   }

   for(i = 0; i <= numero; i++) {
      printf("%d", vetor[i]);
   }
} 
          
   
