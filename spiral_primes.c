


#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define END_PERCENT     10


int main(int argc, char** argv);
int is_prime(int64_t s);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        /* Here we can map the values of each number on the di
         *
         * S0 = n**2;
         * S1 = n**2 - (n - 1);
         * S2 = n**2 - 2(n - 1);
         * S3 = n**2 - 3(n - 1);
         *
         * Notably, we don't care about anything which is obviously a sqaure
         * number for it will never be a prime. */

        int64_t s1, s2, s3, n;
        int64_t diag_total = 5;
        int64_t count = 3;

        for(n = 5; ; n += 2){

                s1 = (n * n) - (n - 1);
                s2 = (n * n) - 2 * (n - 1);
                s3 = (n * n) - 3 * (n - 1);

                count += is_prime(s1) + is_prime(s2) + is_prime(s3);

                diag_total += 4;

                if((100 * count) / diag_total < END_PERCENT){
                        break;
                }

        }

        printf("%"PRId64"\n", n);

        return 0;

}

int is_prime(int64_t s)
{
        if (s < 2 || s == 2 || s % 2 == 0)
                return (s == 2);

        int64_t top = (int64_t) round((double) sqrt(s));

        for(int64_t i = 3; i <= top; i += 2){

                if (s % i == 0)
                        return 0;
        }

        return 1;
}

