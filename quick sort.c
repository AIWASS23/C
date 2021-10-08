#include <stdio.h>
#include <stdlib.h>
#define MAX 10
 
void quick_sort(int *a, int esq, int dir);
 
int main(int argc, char** argv){
    int i;
    int vet[MAX];
 
    for(int i = 0; i < MAX; i++){
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }
 
    quick_sort(vet, 0, MAX - 1);
 
    printf("\n Valores ordenados \n");

    for(int i = 0; i < MAX; i++){
        printf("%dn", vet[i]);
    }
    system("pause");
    return 0;
}
 
void quick_sort(int *a, int esq, int dir){
    int i, j, x, y;
     
    i = esq;
    j = dir;
    x = a[(esq + dir) / 2];
     
    while(i <= j){
        while(a[i] < x && i < dir){
            i++;
        }
        while(a[j] > x && j > esq){
            j--;
        }
        if(i <= j){
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quick_sort(a, esq, j);
    }
    if(i < dir) {
        quick_sort(a, i, dir);
    }
}