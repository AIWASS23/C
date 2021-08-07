#include <stdio.h>
#include <conio.h>

float fatorial (float n){
       int i;
       float t=1;
       for(i=1;i<=n;i++){t*=i;}
       return t;
}
float comb (float n, float p){
       float t;
       t=fatorial(n)/(fatorial(p)*fatorial(n-p));
       return t;
}
int main (){
    float n,p,t;
    printf("Digite n/p\n");
    scanf("%f/%f",&n,&p);
    t=comb(n,p);
    printf("C(%f,%f) = %f",n,p,t);
    getch();
	return 0;
}
