#include<stdio.h>
#include<conio.h>

float g(float num){
	return (num);
}

float x(float num2){
	return (num2);
}

int main(){
	float t1,t2,n,h,xi,k = 0.0;
   int i = 0;

   printf("Digite T1: ");
   scanf("%f",&t1);

   printf("Digite T2: ");
   scanf("%f",&t2);

   printf("Digite N: ");
   scanf("%f",&n);

if((t2>t1)&&(n>0)){
	h=(t2-t1)/n;
   xi=x(t1);

for(i=0;i<n;i++){
	k=h*g(xi);
   xi=xi+k;

   float aux = t1+i*h;

   printf("%f %f\n",aux,xi);

   getch();

}

}

return(0);

}