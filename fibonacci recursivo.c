#include <stdio.h>

int fibo(int n){
    if (n == 1) {
        return 1;
    }else if(n == 2)return 1;
    else return fibo(n - 1) + fibo(n - 2);
}
int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d \n", fibo(n));
    return 0;
}
