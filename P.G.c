#include<stdio.h>
#include<math.h>

int main(){
  int i,n,sum=0,num1,num2,razao,series,finalnum;

  printf("Digite os 2 numeros para sabemos a diferença\n");
  scanf("%d%d",&num1,&num2);

  printf("Digite o numero de termos da serie\n");
  scanf("%d",&n);

  razao = num2/num1;

  printf("a razao eh: %d\n",razao);
  finalnum=(num1*(pow(razao,(n-1))));

  printf("o ultimo termo da serie eh: %d\n",finalnum);
  sum=(num1*(1-pow(razao,n)))/(1-razao);
  series=num1;

  printf("Soma da serie: \n");

  for(i=1;i<=n;i++){
    if(i<n){
      printf("%d",series);
      series*=razao;
    }
    else{
      printf("%d=%d\n",series,sum);
      series*=razao;
    }
  }
  return 0;
}