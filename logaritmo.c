#include <stdio.h>
#include <math.h>

int main (void) {

   double s = 0.0;
   double l = 0.0;
   double x = 21397534.0;

//   int q = 0;

   s = sqrt(sqrt(x));

   do {

      l = exp(s);
      s -= ((l-x)/l);

//      printf ("q=%4d\tx=%15.25f\ts=%15.25f\n", q, x, s);

//      q++;

   } while (l/x>1);

//   printf ("q=%4d\tx=%15.25f\tl=%15.25f\ts=%15.25f\n", q, x, l, s);
   printf("e^%15.25f=%15.25f\n", s, exp(s)); 

   return 0;

}