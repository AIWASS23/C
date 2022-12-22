#include <stdio.h>
#include <stdlib.h>
#define L 3
#define C 4
int main(int argc, char *argv[])
{
int mt[L][C];
int i,j;

printf("\tMatriz\n\n");

for(i=0;i<L;i++){
                 
                 for(j=0;j<C;j++){
                 printf("Digite os Numeros da posicao: Linha: %d\t Coluna: %d\t",i,j);
                 scanf("%d",&mt[i][j]);
                 }                
}
for(i=0;i<L;i++){
printf("\n");                 
    for(j=0;j<C;j++){
    printf(" %d",mt[i][j]);
    
    }             
printf("\n\n");
}

system("PAUSE");	
return 0;
}
