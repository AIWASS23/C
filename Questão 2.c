#include <stdio.h>

int main(){
    int vetor[6]={10,1,4,100,-7,8};
    int i,j,aux;
    
    for(int j=0;j<6;j=j+1){
        for(int i=0;i<6;i=i+1){
            if(vetor[i]<vetor[i+1]){
                aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
               
            }
         }
      }
     for(int i=0;i<=5;i=i+1){
        printf("%d\n",vetor[i]);
     }
    return 0;
}
