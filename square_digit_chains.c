
/* Inclusions */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>


/* Definitions */
#define MAX     10000000


/* Function Prototypes */
uint32_t numberChain(uint32_t i);
inline uint32_t sqr(uint32_t i);
int main(int argc, char** argv);

int main(int argc, char** argv)
{
        uint32_t count = 0;

        for(uint32_t i = 1; i < MAX; i++){

                count += (89 == numberChain(i));
        }

        printf("%"PRIu32"\n", count);


        return 0;

}


uint32_t numberChain(uint32_t i)
{
        uint32_t sum = 0;

        while(1){

                /* Finds the sum of square of numbers in loop */
                for(sum = 0; i != 0 ; ){
                        sum += sqr(i % 10);
                        i /= 10;
                }

                i = sum;

                if(sum == 1 || sum == 89) break;
        }

        return sum;

}

inline uint32_t sqr(uint32_t i)
{
        return i * i;
}

