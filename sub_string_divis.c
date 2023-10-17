

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>


#define START           1023456789
#define MAX             4999999999
#define BASE            10


static const int PRIMES[] = {17, 13, 11, 7, 5, 3, 2};


int is_pandigit(uint64_t i);
int substring_divis(uint64_t n);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* A couple of things that speed up our computation:
         *
         *      All pandigital numbers (0-9) are divisible by 9 so we can
         *      increment by 9 to reduce our search space. We start with the
         *      first known pandigital number, so we know each subsequently
         *      generated number is far more likely to be one too.
         *
         *      I have found that it is also considerably more computationally
         *      efficient to first check if the number is substring divisible
         *      before checking whether it is a pandigit. This is because all
         *      numbers --irrespective of their unsuitability-- must be checked
         *      and my algorithm for checking if it is pandigital relies on
         *      sorting the number first even before any suitability checking
         *      can commence. This means that it takes O(n log n) time. */

        uint64_t sum = 0;

        for(uint64_t i = START; i < MAX; i += 9){
                sum += i * (substring_divis(i) && is_pandigit(i));
        }

        printf("%"PRIu64"\n", sum);

        return 0;

}


/* Testing the pandigital nature of numbers by identifying the digit that is
 * removed from the number and using that to set bits in an integer that tracks
 * which digits have been selected. I am hellishly proud of this method. It is
 * very efficient and uses very little memory */
int is_pandigit(uint64_t i)
{
        uint32_t bit_mask = 0x0;

        for(uint32_t set_ints = 0x0; i; i /= BASE){
                bit_mask = 0x1;
                bit_mask <<= i % BASE;
                set_ints ^= bit_mask;

                if(!(set_ints & bit_mask)){
                        return 0;
                }
        }

        return 1;

}


int substring_divis(uint64_t n)
{
        for(uint8_t i = 0; n > 1000; n /= BASE){

                if((n % 1000) % PRIMES[i++]){
                        return 0;
                }
        }

        return 1;

}

