
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

/* Definitions */
#define START   40755

/* Prototypes */
int main(int argc, char** argv);
int pentagonal(uint64_t x);
int hexagonal(uint64_t x);
int natural(double x);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t tri = 0;
        uint32_t res = 0;

        for(uint64_t n = START + 1; !res; n++){

                /* Generate triangular number */
                tri = n * ((n + 1) / 2);

                res = (pentagonal(tri) && hexagonal(tri));
        }


        printf("%"PRIu64"\n", tri);

        return 0;

}


/* Checks if a number is pentagonal by
 * taking the inverse function and
 * checking if it is a natural number */
int pentagonal(uint64_t x)
{
        double p = (sqrt(24 * x + 1) + 1) / 6;

        return natural(p);
}


/* Checks if a number is hexagonal by
 * taking the inverse function and
 * checking if it is a natural number */
int hexagonal(uint64_t x)
{
        double h = (sqrt(8 * x + 1) + 1) / 4;

        return natural(h);
}


int natural(double x)
{
        return (floorf(x) == x);
}

