

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX     999
#define BASE    10
#define START   100


int main(int argc, char** argv);
int isPalindrome(uint32_t i);
uint32_t intrev(uint32_t i);


int main(int argc, char** argv)
{
        uint32_t test; uint32_t longest;

        /* Fuck this waterfall, like really */
        for(uint32_t i = START; i < MAX; i++){
                for(uint32_t j = START; j < MAX; j++){

                        test = i * j;

                        if(isPalindrome(test) && test > longest){
                                        longest = test;
                        }
                }
        }

        printf("%"PRIu32"\n", longest);

        return 0;

}


uint32_t intrev(uint32_t i)
{
        uint32_t rev = 0;
        uint32_t rem;

        while(i){
                rem = i % BASE;
                rev *= BASE;
                rev += rem;
                i /= BASE;
        }

        return rev;
}


int isPalindrome(uint32_t i)
{
        return (i == intrev(i));
}

