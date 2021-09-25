
#include <stdio.h>
#include <stdlib.h>

double fatorial(int t){
	
   double aux;
   aux = t;
   
   while(t > 1){
   	
      aux = aux * (t - 1);
      t--;
   }

   return (aux);
}


double power(double b, int e){
   double resultado;
   int i;

   resultado = 1;
   
   if(e == 0){
   	 return 1;
   }	 
   for(i = 0;i < e; i++){
   	
   	resultado = resultado * b;
      return (resultado);
    }
}


double serie_seno(double x, int t1){
	
   int i;
   double resultado;
   resultado = 0;

   for(i = 0; i < t1;i++){
      resultado += power(-1, i) * power(x, 2*i + 1) / fatorial(2*i + 1);
   }

   return (resultado);
}


double seno(){
	
   double x;
   int termos;

   system("clear");

   printf("****sen(x) pelo polinomio de Taylor****\n\n");
   printf("Digite o numero de termos da sequencia: " );
   scanf("%d", &termos);
   printf("\nDigite o valor de x para o calculo do sen(x), x = ");
   scanf("%lf", &x);


   printf("\n\nO resultado e: %1.15lf\n\n", serie_seno(x, termos));

   getchar();
   return 0;
}


int main(){

   seno();
   return 0;
}
