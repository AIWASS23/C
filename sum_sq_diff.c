

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


#define MAX             100
#define SQUARE(n)       ((n) * (n))


int main(int argc, char** argv);
int64_t sum_consec_squares(int64_t);
int64_t sum_consec_int(int64_t);


int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int64_t total = sum_consec_int(MAX);

        printf("%"PRIu64"\n", SQUARE(total) - sum_consec_squares(MAX));
}

int64_t sum_consec_squares(int64_t n)
{
        return (n * (n + 1) * (2 * n + 1)) / 6;
}

int64_t sum_consec_int(int64_t n)
{
        return n * (n + 1) /2;
}

