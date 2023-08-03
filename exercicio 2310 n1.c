#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

  unsigned char byte=atoi(argv[1]);
  unsigned char mask=2;
  int res=0;

  if((byte>=1)&&(byte<=10)) {
    res=byte >> mask;
   //" deslocar os bits de $a $b para direita"
  } else {
   res=byte+4;
  }

  printf("byte=%d res=%d\n", byte, res);


  return 0;
}
