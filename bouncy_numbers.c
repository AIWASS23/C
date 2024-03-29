#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define START           21780
#define START_RATIO     90
#define END_RATIO       99
#define DIGIT_LEN       10


int eval_bouncy(int i, int (*cmp)(uint32_t, uint32_t));
int desc(uint32_t a, uint32_t b);
int asc(uint32_t a, uint32_t b);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* Start with a known proportion and go from there
         * up until we find the expected ratio */
        uint32_t i = START + 1;

        for(uint32_t count = (START * START_RATIO) / 100; count; i++){

                count += (!eval_bouncy(i, desc) && !eval_bouncy(i, asc));

                /* We do this little dance where we take the percentage to
                 * avoid floating point calculations and flawed comparisons. We
                 * also ensure that the number we produce is evenly divisible
                 * so we don't get a result that is approximate */
                uint32_t curr = (i * END_RATIO) / 100;

                if(curr == count && !((i * END_RATIO) % 100)){
                        break;
                }
//                count = (curr == count && !((i * END_RATIO) % 100)) ? 0 : count;
        }

        printf("%"PRIu32"\n", i);

        return 0;

}


inline int desc(uint32_t a, uint32_t b)
{
        return a > b;
}


inline int asc(uint32_t a, uint32_t b)
{
        return a < b;
}


/* We pass in a pointer to a function that either compares that two numbers are
 * descending, or ascending. This is accompanied by the integer which we
 * successively take digits off and compare with the previous number to yield
 * whether it is neither ascending nor descending. */
int eval_bouncy(int i, int (*cmp)(uint32_t, uint32_t))
{

        uint32_t last = i % 10;

        for(i /= 10; i; i /= ((last = i % 10), 10)){

                if(cmp(i % 10, last)){
                        break;
                }
        }

        return !i;

}

