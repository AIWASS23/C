#include <stdio.h>
#include <stdlib.h>

#define VETOR 7  
#define QUARTO 6  
#define INTERVALO 10  

struct Node {
    int data;
    struct Node *next;
};

void BucketSort(int vet[]);
struct Node *InsertionSort(struct Node *lista);
void imprime(int vet1[]);
void imprime_Quarto(struct Node *lista1);
int getQuartoIndex(int valor);

void BucketSort(int vet3[]) {
    int i, j;
    struct Node **quartos;

    quartos = (struct Node **)malloc(sizeof(struct Node *) * QUARTO);

    for (int i = 0; i < QUARTO; ++i) {
        quartos[i] = NULL;
    }

    for (int i = 0; i < VETOR; ++i) {
        struct Node *current;
        int pos = getQuartoIndex(vet3[i]);
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = vet3[i];
        current->next = quartos[pos];
        quartos[pos] = current;
    }

    for (int i = 0; i < QUARTO; i++) {
        printf("vetor[%d]: ", i);
        imprime_Quartos(quartos[i]);
        printf("\n");
    }

    for (int i = 0; i < QUARTO; ++i) {
        quartos[i] = InsertionSort(quartos[i]);
    }

    printf("-------------\n");
    
    for (int i = 0; i < QUARTO; i++) {
        printf("vetor[%d]: ", i);
        imprime_Quartos(quartos[i]);
        printf("\n");
    }

    for (int i = 0, j = 0; i < QUARTO; ++i) {
        struct Node *node;
        node = quartos[i];

        while (node) {
            vet3[j++] = node->data;
            node = node->next;
        }
    }

}

struct Node *InsertionSort(struct Node *lista) {
    struct Node *k, *nodeLista;
    if (lista == 0 || lista->next == 0) {
        return lista;
    }

    nodeLista = lista;
    k = lista->next;
    nodeLista->next = 0;

    while (k != 0) {
        struct Node *ptr;
        if (nodeLista->data > k->data) {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeLista;
            nodeLista = tmp;
            continue;
        }

    for (ptr = nodeLista; ptr->next != 0; ptr = ptr->next) {
        if (ptr->next->data > k->data)
            {break;}
    }

    if (ptr->next != 0) {
        struct Node *tmp;
        tmp = k;
        k = k->next;
        tmp->next = ptr->next;
        ptr->next = tmp;
        continue;
    } else {
        ptr->next = k;
        k = k->next;
        ptr->next->next = 0;
        continue;
    }
  }
  return nodeLista;
}

int getQuartoIndex(int valor) {
  return valor / INTERVALO;
}

void imprime(int vet1[]) {
    int i;
    for (int i = 0; i < VETOR; ++i) {
        printf("%d ", vet1[i]);
    }
    printf("\n");
}

void imprime_Quartos(struct Node *lista1) {
    struct Node *cur = lista1;

    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void){
    int array[VETOR] = {42, 32, 33, 52, 37, 47, 51};

    print(array);
    printf("-------------\n");

    BucketSort(array);

    printf("-------------\n");
    print(array);

    return 0;
}
