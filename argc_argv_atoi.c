#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{

  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]);

  int ss = soma(num1, num2);

  printf(" %d + %d = %d \n", num1, num2, ss);

  return 0;
}
