#include <stdio.h>
  
void trocar(int *a, int *b){
    int tempo = *a;
    *a = *b;
    *b = tempo;
}
  
void montar_pilha(int vet[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
  
    if (esq < n && vet[esq] > vet[maior])
        {maior = esq;}
  
    if (dir < n && vet[dir] > vet[maior])
        {maior = dir;}
  
    if (maior != i) {
        trocar(&vet[i], &vet[maior]);
        montar_pilha(vet, n, maior);
    }
}
  
void heapSort(int vet1[], int y) {
    for (int i = y / 2 - 1; i >= 0; i--)
        {montar_pilha(vet1, y, i);}
  
    for (int i = y - 1; i >= 0; i--) {
        trocar(&vet1[0], &vet1[i]);
        montar_pilha(vet1, i, 0);
    }
}
  
void imprime_Vetor(int vet2[], int x){
    for (int i = 0; i < x; ++i)
        {printf("%d ", vet2[i]);}
    printf("\n");
}
  

int main() {
    int vet3[] = {1, 12, 9, 5, 6, 10};
    int z = sizeof(vet3) / sizeof(vet3[0]);
  
    heapSort(vet3, z);
  
    imprime_Vetor(vet3, z);
}