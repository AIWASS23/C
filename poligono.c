#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int x1,x2,y1,y2;

struct pixel
{
 float x;
 float y;
 float z;
};

struct pixel valor[20];
struct pixel funcao[3];
struct pixel resultado[20];

void reta(int x1,int y1, int x2, int y2)
{
 float a,b,d;
 int x,y;
 int aux;
 int alternativa,princ;

 princ = 0;

 if((x1>x2)&&(y1!=y2))
 {
  x = x2; y = y2;
  x2 = x1; y2 = y1;
  x1 = x; y1 = y;
 }
 else
 {
   if( x1 == x2 )
   {
     princ = 1;
     if(y1 > y2)
     {
       y = y2;
       y2 = y1;
       y1 = y;
      }
    }
   if(y1==y2)
   {
     princ = 2;
     if(x1 > x2)
     {
       x=x2;
       x2=x1;
       x1=x;
      }
   }
   x = x1;
   y = y1; }

 if(princ>0)
 { a = 0; }
 else
 {
   a = (float)(y2 - y1)/(float)(x2 - x1); }
   b = (float)(y2 - a * x2);

 alternativa = 0;

 if ( a < 0 )
 {
   y1 = -y1; y2 = -y2;
   a = (float)(y2 - y1)/(float)(x2 - x1);
   b = (float)(y2 - a * x2);
   x = x1;
   y = y1;
   alternativa = 2;
 }

 if(a>1)
 {
   aux = x1; x1 = y1; y1 = aux;
   aux = x2; x2 = y2; y2 = aux;
   a = (float)(y2 - y1)/(float)(x2 - x1);
   b = (float)(y2 - a * x2);
   x = x1;
   y = y1;
   if (alternativa == 2)
   { alternativa = 3; }
   else
   { alternativa = 1; }
 }

 while((x <= x2) && (y <= y2))
 {
   if(alternativa == 0)
   {putpixel(x,y,WHITE); }
   if(alternativa == 1)
   {putpixel(y,x,WHITE); }
   if(alternativa == 2)
   {putpixel(x,-y,WHITE); }
   if(alternativa == 3)
   {putpixel(y,-x,WHITE); }
   if(princ == 0)
   {
     d = (float)((a*(x+1))+(b-(y+0.5)));
     if (d >= 0)
     { x+=1;y+=1;}
     else
     { x+=1; }
   }

   if(princ == 1)
   {y+=1; }
   if(princ == 2)
   {x+=1; }
 }
}

void poligono( struct pixel poli[20] )
{
 int i;

 i = 0;

 while ((poli[i].x != NULL) && (poli[i].y != NULL))
 {
   if (i == 0)
   { x1 = poli[i].x; y1 = poli[i].y; }
   else
   { x1 = x2; y1 = y2; }

   x2 = poli[i].x;
   y2 = poli[i].y;

   reta( x1, y1, x2, y2 );

   i++;
 }

 x1 = x2; y1 = y2;
 x2 = poli[0].x;
 y2 = poli[0].y;
 reta( x1, y1, x2, y2 );
 getch();
}

void inicio(void)
{
 int gdriver = DETECT, gmode, errorcode;

 /*inicializando o alternativa grafico*/
 initgraph(&gdriver, &gmode, "");
 errorcode = graphresult();
 if (errorcode != grOk)
 {
  printf("Graphics error: %s\n", grapherrormsg(errorcode));
  printf("Press any key to halt:");
  getch();
  exit(1);
 }
}

void fim(void)
{
 /*encerrando o alternativa grafico*/
 closegraph();
}

void mostrar( struct pixel poli[20] )
{
 int i;

 for( i=0; i<20; i++ )
 {
  printf("%d  ",poli[i].x);
 }
 printf("\n");
 for( i=0; i<20; i++ )
 {
  printf("%d  ",poli[i].y);
 }
 printf("\n");
 for( i=0; i<20; i++ )
 {
  printf("%d  ",poli[i].z);
 }
 printf("\n");
}



int main(void)
{
 int i;
 for(i=0; i<20; i++ )
 { valor[i].x = NULL; valor[i].y = NULL; }

 valor[0].x = 1;  valor[0].y = 120; valor[0]. z = 1;
 valor[1].x = 100; valor[1].y = 300; valor[1]. z = 1;
 valor[2].x = 230; valor[2].y = 300; valor[2]. z = 1;
 valor[3].x = 570; valor[3].y = 30;  valor[3]. z = 1;
 valor[4].x = 570; valor[4].y = 320; valor[4]. z = 1;
 valor[5].x = 50; valor[5].y = 480; valor[5]. z = 1;

inicio();

 /*alternativa grafico inicializado sem erros*/
 poligono( valor );

 fim();
 clrscr();
 return 0;
}
