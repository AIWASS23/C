#include<stdio.h>

int main(){
	int n,i;
   int sum=0;

   printf("somador entre 1 e o numero digitado")
   printf("digite um numero para calculamos a soma ");
   scanf("%d",&n);
    
   sum = (n * (n + 1)) / 2;
   printf("A soma total: ");
    
   for(int i =1;i <= n;i++){
   	if (i!=n) 
   	   {printf("%d + ",i);}
       else
         {printf("%d = %d ",i,sum);}
   }
   return 0;
}
