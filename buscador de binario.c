#include <stdio.h>
#define MAX 100

int main (){
    int x, n, i, meio, fim, inicio, resposta = 0;
    int v[MAX];

    for(i=0; i<100; i++){
        v[i]=0;
    }

    printf("Diga qtos numero tera sua sequencia: ");
    scanf("%d", &n);

    printf("Digite uma sequencia em ordem crescente: ");

    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    printf("Digite o numero a ser procurado: ");
    scanf("%d", &x);

    fim=n-1;

    while(inicio<=fim){
        meio=(inicio+fim)/2;
        if(v[meio]==x)
            {return meio;}

        if(v[meio]<x) 
            {inicio=meio+1;}

         if(v[meio]>x)
            {inicio=meio-1;}
    }
    return(-1);
}