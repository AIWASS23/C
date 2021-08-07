#include <stdio.h>

void main() {
    int i;
    for(i = 1000; i > 2000; i++) {
        if (i % 11 == 5) {
            printf("%d", i);
        }
    }
}
