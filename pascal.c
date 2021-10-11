#include<stdio.h>
#include<conio.h>
long calc( int );

int main(){
 int i,j,row,pas;
 
 printf("Digite o numero para fazemos otrângulo pascal : ");
 scanf("%d", &row);
 
 for(int i=0; i<row; i++){
   for(int j=0; j<=(row-i-1); j++)
     {printf(" ");}
     
   for(int j=0; j<=i; j++){
     pas=calc(i)/(calc(j)*calc(i-j));
     printf("%ld ",pas); 
   }
   
   printf("\n");
   
 }
 getch();
 return 0;
}

long calc( int num){
 int x;
 long res=1;
 
 for(int x=1; x<=num; x++)
   {res=res*x;}
 return (res);
}