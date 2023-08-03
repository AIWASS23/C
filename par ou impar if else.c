#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc < 2)
    {
      printf("Digite um numero valido! \n");
      return -1;
    }
  int num = atoi(argv[1]);

  if(num % 2 == 0)
     printf("%d é par!");
  else
     printf("%d NÂO é par!");

  return 0;
}
