#include<stdio.h>

int main(){
  int i,n,soma=0,num1,num2,diferenca,finalnum,series;

  printf("Insira os 2 primeiros números para encontrar a diferença comum\n");
  scanf("%d%d",&num1,&num2);
  
  printf("Digite o último termo da série \n");
  scanf("%d",&finalnum);

  diferenca=num2-num1;
  series=num1;

  n=((finalnum-num1)/diferenca)+1;
  printf("Numeros de termos da serie eh: %d\n",n);

  for(i=1;i<=n;i++){
    soma+=series;
    series+=diferenca;
  }

  series=num1;
  printf("soma da serie eh:\n");

  for(i=1;i<=n;i++){
    if(i<n){
      printf("%d+",series);
      series+=diferenca;
    }
    else{
      printf("%d=%d\n",series,sum);
      series+=diferenca;
    }
  }
  return 0;
}