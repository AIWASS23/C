#include <stdio.h>

int soma(int n1, int n2) // soma(2,3)
{
  int s = n1 + n2;
  return s;
}

int main()
{
  int ss = soma(2,3);

  printf(" soma = %d \n ", ss);

  return 0;
}
