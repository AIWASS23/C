#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE_PECAS 8
#define SEGUNDO_JOGADOR 0
#define PRIMEIRO_JOGADOR 1

typedef struct{
	
  unsigned short x,y;
  unsigned char usada,dama;
}TPeca;

void IniciaPecas(TPeca *p,int jogador);

int main(){
  
  TPeca *jogador1=malloc(sizeof(TPeca)*QUANTIDADE_PECAS),*jogador2=malloc(sizeof(TPeca)*QUANTIDADE_PECAS);
  int d;
  
  if(!(jogador1&&jogador2))
    return(-1);
  
  
  IniciaPecas(jogador1,PRIMEIRO_JOGADOR);
  jogador1[3].usada=0;
  IniciaPecas(jogador2,SEGUNDO_JOGADOR);
  jogador2[4].dama=1;

  
  for(d=0; d<QUANTIDADE_PECAS; d++)
    printf("\n%s|\t%s:\t%i,%i",jogador1[d].usada?"Usado":"Não usado",jogador1[d].dama?"E dama":"Não e dama",jogador1[d].x,jogador1[d].y);
  printf("\n\n");
  for(d=0; d<QUANTIDADE_PECAS; d++)
    printf("\n%s|\t%s:\t%i,%i",jogador2[d].usada?"Usado":"Não usado",jogador2[d].dama?"E dama":"Não e dama",jogador2[d].x,jogador2[d].y);
  
  free(jogador1);
  free(jogador2);
  getchar();
  return(0);
}

void IniciaPecas(TPeca *p,int jogador){
	
  unsigned char i,x=1,y=1;
  if(jogador)
  
    for(i=0; i<QUANTIDADE_PECAS; i++){
    	
      p[i].usada=1;
      p[i].dama=0;
      
      if(x>8){
      	
        y++;
        x=1;
      }
      p[i].x=x;
      p[i].y=y;
      x+=2;
    }
  else
  
    for(i=0; i<QUANTIDADE_PECAS; i++){
    	
      p[i].usada=1;
      p[i].dama=0;
      if(x>8){
      	
        y++;
        x=1;
      }
      p[i].x=x;
      p[i].y=y+4;
      x+=2;
    }
}