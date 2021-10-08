#include <stdio.h>

void merge(int ver[], int x, int y, int z) {

  int n1 = y - x + 1;
  int n2 = z - y;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    {L[i] = ver[x + i];}
  for (int j = 0; j < n2; j++)
   {M[j] = ver[y + 1 + j];}

  int i, j, k;
  i = 0;
  j = 0;
  k = x;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      ver[k] = L[i];
      i++;
    } else {
        ver[k] = M[j];
        j++;
    }
    k++;
  }

  while (i < n1) {
    ver[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    ver[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int ver1[], int a, int b) {
  if (a < b) {
    int m = a + (b - a) / 2;

    mergeSort(ver1, a, m);
    mergeSort(ver1, m + 1, b);
    merge(ver1, a, m, b);
  }
}

void imprime_Array(int ver2[], int size) {
  for (int i = 0; i < size; i++)
    {printf("%d ", ver2[i]);}
  printf("\n");
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array: \n");
  imprime_Array(arr, size);
}
