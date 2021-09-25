#include <stdio.h>
#include <math.h>

static long fat = 1;

int main(){
	
  int n, i, j;
  double x, z = 0.0;

  scanf("%lf%d", &x, &n);

  for (i = 0; i < n; i++ ){
  	
    printf("* i=%d fat(%d)=%d\n", i, 2*i, fat);
    z = z + ( ( pow(-1.0 , i)*pow(x, (2.0*i)) ) / fat );
    fat = fat * (2*i+1) * (2*i+2);
  }

  printf("\n\ncos(x) = %lf\n", z );

  return 0;
}
