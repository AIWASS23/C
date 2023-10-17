
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define PERIMETER       1000


int main(int argc, char** argv);
int ispythag(uint32_t a, uint32_t b, uint32_t c);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint32_t a, b, c;

        for(a = 1; a < PERIMETER; a++){

                for(b = 1; b < PERIMETER; b++){

                        c = PERIMETER - (a + b);

                        if(ispythag(a, b, c)){
                                goto out;
                        }

                }

        }

out:

        printf("%"PRIu32"\n", a * b * c);

        return 0;
}

int ispythag(uint32_t a, uint32_t b, uint32_t c)
{
        return ((a * a) + (b * b) == (c * c));
}

