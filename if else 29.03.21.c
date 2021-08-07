#include <stdio.h>

int a = 3, b = 4, c = 8;

int main(){
if ((a > 3) && (c == 8)) {
    printf("verdadeiro \n");
}
else{
    printf("falso \n");
}
if ((a != 2) || (b <= 5)) {
    printf("verdadeiro \n");
}
else{
    printf("falso \n");
}
if ((a == 3) || (b >= 2) && (c == 8)) {
    printf("verdadeiro \n");
}
else{
    printf("falso \n");
}
if ((a == 3) && !((b <= 4) && (c == 8))) {
    printf("verdadeiro \n");
}
else{
    printf("falso \n");
}
if ((b > a) && (c != a)) {
    printf("verdadeiro \n");
}
else{
    printf("falso \n");
}
if ((a > b) || (b < 5)) {
    printf("verdadeiro \n");
}
else{
    printf("falso \n");
}

}
