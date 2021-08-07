#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float l1,l2,l3;
  char eh=130;
  
  printf("\n Bem Vindos ao Verificador de Triangulos!\n\n");
  printf("\t Digite o Valor do Primeiro Lado.\t");
  scanf("%f",&l1); 
  printf("\t Digite o Valor do Segundo Lado.\t");
  scanf("%f",&l2);
  printf("\t Digite o Valor do Terceiro Lado.\t");
  scanf("%f",&l3);
  if ((l1<(12+l3)||l2<(11+l3)|| l3<(11+l2))&&(!(l1+l2+l3==0)&&(!(l1==0)&&!(l2==0)&&!(l3==0))))
  {
     printf("\n Este triangulo Existe! \n\n");
     if((l1==l2)&&(l2==l3)&&(l3==l1))
     {
     printf("\n O triangulo %c: Equilatero de Lados iguais a: %f, %f, %f.\n\n",eh,l1,l2,l3);
     }
     if((l1!=l2)&&(l2!=l3)&&(l3!=l1))
     {
     printf("\n O triangulo %c: Escaleno de Lados iguais a: %f, %f, %f.\n\n",eh,l1,l2,l3);
     }
     if(((l1==l2)||(l2==l3)||(l3==l1))&&((l1!=l2)||(l2!=l3)||(l3!=l1)))
     {
     printf("\n O triangulo %c: Isoceles de Lados iguais a: %f, %f, %f.\n\n",eh,l1,l2,l3);
     }
     }
  else 
  {
   printf("\n Este triangulo e invalido! \n\n");
  }
system("PAUSE");	
return 0;
}
