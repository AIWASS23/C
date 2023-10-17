
/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


/* Definitions */
#define MAX_LEN 20
#define MIN     1020304050607080900 


/* Prototypes */
int isConcealedSquare(uint64_t i);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        uint64_t test; uint64_t i;

        for(i = 0; ; i+= 2){

                test = i*i;

                if(test < MIN) continue;

                if(isConcealedSquare(test)) break;

        }
        
        printf("%"PRIu64"\n", i);

	return 0;

}


int isConcealedSquare(uint64_t i)
{
        if(i % 10 != 0) return 0;
        i /= 100;

        for(uint32_t a = 9; i; a--){
                if(i % 10 != a) return 0;
                i /= 100;
        }

        return 1;

}

