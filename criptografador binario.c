#include<stdio.h>
#include<string.h>
int main(){
  int i,tempo,x;
  int y = 1;
  int binario=0;
  char str[1000];

  printf("digite sua sentença\n");
  gets(str);

  int i=0;

  printf("criptografador binario\n");

  while(str[i]!='\0'){
    int y = 1;
    int binario = 0;
    tempo = str[i];

    while(tempo != 0){
      x = tempo % 2;
      binario = binario + (x * y);
      tempo = tempo / 2;
      y = y * 10;
    }

    printf("%d ",binario);

    i++;
  }

  printf("\n");
  
}