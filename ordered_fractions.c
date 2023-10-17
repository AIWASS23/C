

#include <stdio.h>
#include <stdint.h>


#define MAX     1000000

static const double three_sevenths = 3.0 / 7.0;

struct frac {
        int32_t n;
        int32_t d;
        double fp;
};

int32_t gcd(int32_t a, int32_t b);
int main(int argc, char** argv);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        struct frac left = {2, 7, (double) 2.0/7.0};

        for(int32_t n = 4; n < MAX; n++){

                int32_t STEP = (n & 0x1) ? 1 : 2;

                for(int32_t d = (n * 7 / 3) - 1; d < MAX; d += STEP){

                        double tmp = (double) n / (double) d;

                        if(tmp > three_sevenths){
                               continue;
                        }

                        if(tmp > left.fp){

                                if(gcd(n, d) != 1){
                                        continue;
                                }

                                left.n = n;
                                left.d = d;
                                left.fp = tmp;
                        }

                        if(tmp < three_sevenths){
                                break;
                        }

                }

        }

        printf("%d/%d\n", left.n, left.d);


        return 0;

}

/* Euler's Method to find the greatest common divisor */
int32_t gcd(int32_t a, int32_t b)
{
        int32_t tmp;

        while(b){
                tmp = a % b;
                a = b;
                b = tmp;
        }

        return a;

}

