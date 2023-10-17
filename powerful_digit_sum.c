#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


#define MAX             100
#define BASE            10


int main(int argc, char** argv);
uint64_t digitalSum(mpz_t i);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        mpz_t digit; uint64_t max = 0, sum = 0;

        mpz_init(digit);

        for(uint64_t a = 1 ; a <= MAX; a++){

                for(uint64_t b = 1; b <= MAX; b++){

                        mpz_ui_pow_ui(digit, a, b);
                        sum = digitalSum(digit);

                        /* Assign if bigger */
                        max = (sum > max) ? sum : max;
                }

        }

        mpz_clear(digit);

        printf("%"PRIu64"\n", max);

        return 0;

}


/* Very simple cast to string; sum iteration */
uint64_t digitalSum(mpz_t i)
{
        uint64_t sum = 0;

        char* tmp = NULL;
        tmp = mpz_get_str(NULL, BASE, i);

        for(char* str = tmp; *str != '\0'; sum += (uint64_t) (*str++ - '0'))
                ;

        free(tmp);

        return sum;
}

