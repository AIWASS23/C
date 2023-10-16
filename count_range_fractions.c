#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX                     12000
static const double min_frac =  1.0 / 3.0;
static const double max_frac =  1.0 / 2.0;


int32_t gcd(int32_t a, int32_t b);
int main(int argc, char** argv);


int main(int argc, char** argv) {
        (void) argc;
        (void) argv;

        int32_t frac_count = 0;

        for(int32_t n = 1; n <= MAX; n++){

                for(int32_t d = n * 2; d <= MAX; d++){

                        double tmp = (double) n / (double) d;

                        if(tmp >= max_frac){
                               continue;
                        }

                        frac_count += (tmp > min_frac && gcd(n, d) == 1);

                        if(tmp <= min_frac){
                                break;
                        }

                }

        }

        printf("%"PRId32"\n", frac_count);


        return 0;

}

int32_t gcd(int32_t a, int32_t b) {
        int32_t tmp;

        while(b){
                tmp = a % b;
                a = b;
                b = tmp;
        }

        return a;

}

