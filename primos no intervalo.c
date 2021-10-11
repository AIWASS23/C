#include<stdio.h>
int main(){
  int num1,num2,i,count=0,j;

  printf("programa para calcular os numeros primos no intervalo dado")

  printf("Digite o primeiro número:\n");
  scanf("%d",&num1);

  printf("Digite o segundo numero \n");
  scanf("%d",&num2);

  printf("os numeros primos entre %d e %d são:\n",num1,num2);

  for(i=num1;i<=num2;i++){
    count=0;

    for(j=1;j<=i;j++){
      if(i%j==0){
        count++;
      }
    }

    if(count==2){
      printf("%d\n",i);
    }
  }
  return 0;
}