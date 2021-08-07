#include <stdio.h>

  void main() {
    int aritmetica, i, j;
    int vetor1[9];
    int vetor2[9];
      printf("digite os 10 numeros para o calculo \n");
      scanf("%d", &vetor1);
      printf("digite os 10 numeros para o calculo \n");
      scanf("%d", &vetor2);
      printf("menu dos calculos \n");
      printf("1 somar \n");
      printf("2 diminuir \n");
      printf("3 multiplicar \n");
      scanf("%d", &aritmetica);

      switch (aritmetica) {
          case 1:
              for (i = 0; i < 10; i++){
                  for (j = 0; j < 10; j++){
                      vetor1[i] = vetor1[i] + vetor2[j];
                      for (i = 0; i < 10; i++){
                          printf("resultado = %d", vetor1[i]);
                      }
                  }
                  printf("\n");
              }
          break;
          case 2:
              for (i = 0; i < 10; i++){
                  for (j = 0; j < 10; j++){
                      vetor1[i] = vetor1[i] - vetor2[j];
                      for (i = 0; i < 10; i++){
                          printf("resultado = %d", vetor1[i]);
                      }
                  }
                  printf("\n");
              }
          break;
          case 3:
              for (i = 0; i < 10; i++){
                  for (j = 0; j < 10; j++){
                      vetor1[i] = vetor1[i] * vetor2[j];
                      for (i = 0; i < 10; i++){
                          printf("resultado = %d", vetor1[i]);
                      }
                  }
                  printf("\n");
              }
          break;
          default:
              printf("numero invalido \n");
      }
}
