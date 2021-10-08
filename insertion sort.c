#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
 
void insertion_sort(int *a);
 
int main(int argc, char** argv){
    int i, vet[MAX];
 
    for(int i = 0; i < MAX; i++){
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }
 
    insertion_sort(vet);
 
    printf("Valores ordenados\n");

    for(i = 0; i < MAX; i++){
        printf("%d", vet[i]);
    }
    system("pause");
    return 0;
}

void insertion_sort(int *a){
    int i, j, ins;
  
    for(int i = 1; i < MAX; i++){
        ins = a[i];
        for(int j = i-1; j >= 0 && ins < a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = ins;
    }
}