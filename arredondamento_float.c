#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
   if(argc < 3)
   {
    printf("digite os 2 numeros do intervalo! \n");
    return -1;
   }

   int num1 = (int)round(atof(argv[1]));
   int num2 = (int)round(atof(argv[2]));

   if(num1 > num2)
   {
    printf(" %d deve ser menor do que %d \n ", num1, num2);
    return -2;
   }

   int soma = 0;

   for(int i = num1; i <= num2; i++)
   {
      soma = soma + i;
   }

   printf("soma = %d \n", soma);

   return 0;
}

