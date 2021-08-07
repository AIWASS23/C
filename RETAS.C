
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int d = 0;
int x,y;
int aux;
float a;
float b;
int x1,x2,y1,y2;

float calculaA(int x1, int x2, int y1, int y2)
{
 return((float)(y2-y1)/(float)(x2-x1));
}

float calculaB(int x2,int y2)
{
  return((float)(y2-a*x2));
}

float calculaD(int x,int y)
{
  return ((calculaA(x1,x2,y1,y2))*(x+1)+(calculaB(x2,y2))-(y+(1/2)));
}

void PlotaReta(int x1,int x2,int y1,int y2)
{
 while((x1<x2&&y1<y2))
{
   if(calculaD(x,y)>0)
   {x1 = x1 + 1; y1 = y1 + 1;}
   else
   {x1 = x1 + 1;}
   putpixel(x1,y1,WHITE);
}
}

/*void troca(int a,int b)
{
  aux = a;
  a = b;
  b = aux;
} */

void reta(int x1,int y1, int x2, int y2)
{
 x = x1;
 y = y1;

if(x1==x2)
{
  while(y<y2)
  {
    y+= 1;
    putpixel(x,y,WHITE);
  }
}
else{
  if(y1==y2)
  {
     while(x<x2)
     {
       x+=1;
       putpixel(x,y,WHITE);
     }
  }
  else{
    if(calculaA(x1,x2,y1,y2)<0)
    {
       y1 = -y1;
       y2 = -y2;
       x = x1;
       y = y1;
    }
    if(calculaA(x1,x2,y1,y2)>1)
    {
      aux = x1;
      x1 = y1;
      y1 = aux;
      aux = x2;
      x2 = y2;
      y2 = aux;
      x = x1;
      y = y1;
      calculaA(x1,x2,y1,y2);
      calculaB(x2,y2);
    }
    if((x2<x1)&&(y2<y1))
    {
      aux = x1;
      x1 = x2;
      x2 = aux;
      aux = y1;
      y1 = y2;
      y2 = aux;
      x = x1;
      y = y1;
      calculaA(x1,x2,y1,y2);
      calculaB(x2,y2);
    }
    PlotaReta(x1,x2,y1,y2);
  }
 }
}


int main(void)
{

   /*detectando o driver da placa gráfica*/
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   printf("\n\n\t\tCC751 - Algoritmo de Retas\n\n");
   printf("Entre com as coordenadas da reta (x,y):\n Ponto Inicial:\n");
   scanf("%d",&x1);
   scanf("%d",&y1);
   printf(" Ponto Final:\n");
   scanf("%d",&x2);
   scanf("%d",&y2);
   printf("\n\nPlotando a reta (%d,%d) -> (%d,%d)",x1,y1,x2,y2);
   getch();

   /*inicializando o modo grafico*/
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n",grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   /*modo grafico inicializado sem erros*/

   /*chamando a funcao de retas*/
   reta(x1,y1,x2,y2);

   getch();

   /*encerrando o modo grafico*/
   closegraph();
   return 0;
}

