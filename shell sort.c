#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
 
void shell_sort(int *a, int size);
 
int main(int argc, char** argv){

    int i, vet[MAX];
 
 
    for(int i = 0; i < MAX; i++){
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }
 
    shell_sort(vet, MAX);
 
    printf("nnValores ordenadosn");

    for(int i = 0; i < MAX; i++){
        printf("%d", vet[i]);
    }
    system("pause");
    return 0;
}

void shell_sort(int *a, int size){
    int i , j , val;
    int mar = 1;
  
    do{
        mar = 3 * mar +1;
    }
    while(mar < size);
  
    do{
        mar /= 3;
        for(int i = mar; i < size; i++) {
            val = a[i];
            j = i - mar;

            while (j >= 0 && val < a[j]) {
                a[j + mar] = a[j];
                j -= mar;
            }
            a[j + mar] = val;
        }
    }
    while(mar > 1);
}