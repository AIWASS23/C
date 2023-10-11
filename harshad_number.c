#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#define START   10000
#define MAX     100000000000000
#define PRESUM  90619
#define BASE    10


uint64_t truncateRight(uint64_t i);
uint64_t digital_sum(uint64_t i);
int isHarshad(uint64_t s);
int isPrime(uint64_t s);
int main(int argc, char** argv);

int main(int argc, char** argv) {
    int trunc; int sum = 0;

    for(uint64_t i = 0; i < MAX; i+= 10){

    }

    return 0;

}

int SRTHP(uint64_t max) {
    uint64_t bases[4] = {2,3,5,7};
    uint64_t allowed_append[4] = {1,2,3,7};
    uint64_t res = 0;
    uint64_t inner = 0;

    for(uint32_t i = 0; i < 4; i++) {
        res = bases[i];
        while(res < max){
            inner = res;

            for(uint32_t i = 0; i < 4; i++){
                inner = int_append(inner, allowed_append[i]);
            }
        }
    }
}

int isHarshad(uint64_t s) {
    return (s % digital_sum(s) == 0);
}


int isPrime(uint64_t s) {
    if(s < 1) return 0;

    if (s == 2) return 1;

    int top = (int) round(sqrt(s))+1;

    for(int i = 2; i < top +1 ; i++){

        if(i == top) return 1;

        if (s % i == 0) return 0;
    }

    return 0;
}

uint64_t truncateRight(uint64_t right) {
    for( ; right; right /= BASE){

        if(!isPrime(right))
            return 0;
    }

    return 1;

}

uint64_t strtoint(char *string) {
    int dec = 0;

    while(*string){
        dec = dec * 10 + (*string++ - '0');
    }

    return dec;
}

int32_t intrev(int32_t i) {
    int32_t rev = 0;

    while(i){
        rev *= BASE;
        rev += (i % BASE);
        i /= BASE;
    }

    return rev;
}

int left_trunc(int32_t left) {
    for( ; left; left = intrev(intrev(left) / BASE)){

        if(!isPrime(left))
            return 0;
    }

    return 1;

}

int possibly_trunc(int32_t i) {
    int32_t end;
    int32_t has_2 = 0;

    end = i % BASE;

    if(end != 7 && end != 3)
        return 0;

    for( ; i; i /= BASE){
        end = (i % BASE);

        if(end % 2 == 0){

            if(end == 2){
                if(has_2++)
                    return 0;

            } else {
                return 0;
            }
        }
    }

    return 1;

}

uint64_t digital_sum(uint64_t i) {
    uint64_t digital_sum = 0;

    for( ; i; i /= BASE) {
        digital_sum += i % BASE;
    }

    return digital_sum;
}

uint64_t int_append(uint64_t base, uint64_t offset) {
    return (base * BASE) + offset;
}
