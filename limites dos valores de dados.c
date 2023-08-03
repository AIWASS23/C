#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{


  printf("Tamanhos de tipos\n");
  printf("--------------------------------------------------- \n");
  printf("char = %ld, short int = %ld, int = %ld, long int = %ld \n\n",
            sizeof(char), sizeof(short int), sizeof(int), sizeof(long int)
);




  printf("Limites dos tipos inteiros em <limits.h>: \n");
  printf("-------------------------------------------------- \n");
  printf("char int: %d at� %d\n", CHAR_MIN, CHAR_MAX);
  printf("short int: %d at� %d\n", SHRT_MIN, SHRT_MAX);
  printf("int: %d at� %d\n", INT_MIN, INT_MAX);
  printf("long int: %ld at� %ld\n", LONG_MIN, LONG_MAX);


  printf("Limites dos tipos reais em <float.h>: \n");
  printf("-------------------------------------------------- \n");
  printf("float: %lf at� %lf\n", -FLT_MAX, FLT_MAX);
  printf("double: %lf at� %lf\n", -DBL_MAX, DBL_MAX);

  return 0;
} 

