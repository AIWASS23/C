


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX     28123

int abundant(int32_t i);
int main(int argc, char** argv);
int sum_abundant(int32_t n, int32_t* abund, int32_t max);


int main(int argc, char** argv)
{
        int32_t sum = 0;
        int32_t* abund = calloc(MAX, sizeof(int32_t));

        for(int32_t i = 0; i < MAX; i++){
                abund[i] = !!abundant(i);
        }

        for(int32_t i = 0; i < MAX; i++){
                sum += (!sum_abundant(i, abund, MAX)) ? i : 0;
        }

        printf("%"PRId32"\n", sum);
        free(abund);

        return 0;

}


int abundant(int32_t i)
{
        int32_t sum = 0;

        for(int32_t a = 1; a < i; a++){
                sum += (!(i % a)) ? a : 0;
        }

        return (sum > i);

}


int sum_abundant(int32_t n, int32_t* abund, int32_t max)
{
        int32_t diff = 1;

        for(int32_t i = 0; diff > 0 && i < n; i++){

                if(!abund[i])
                        continue;

                diff = n - i;

                if(diff > 0 && abund[diff]){
                        return 1;
                }
        }

        return 0;

}

