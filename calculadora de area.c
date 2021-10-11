#include<stdio.h>
#include<math.h>

int main(){
      int opcao;

      printf("Digite\n1 Para triângulo \n2 Para quadrado \n3 Para circulo\n4 Para retângulo \n5 Para paralelogramo\n");
      scanf("%d",&opcao);

      switch(opcao){
            case 1:{
                  int a,b,c;
                  float s,area;

                  printf("Digite os lados do triângulo\n");
                  scanf("%d %d %d",&a,&b,&c);

                  s = (float)(a+b+c)/2;
                  area=(float)(sqrt(s*(s-a)*(s-b)*(s-c)));

                  printf("A area do triângulo de lados  %d,%d,%d eh %f\n",a,b,c,area);
                  break;
            }
            case 2:{
                  float side,area;

                  printf("Digite o lado do quadrado\n");
                  scanf("%f",&side);

                  area=(float)side*side;
                  printf("Area of Square is %f\n",area);
                  break;
            }
            case 3:{
                  float raio,area;

                  printf("Digite o raio do circulo\n");
                  scanf("%f",&raio);

                  area=(float)3.14159*radius*radius;
                  printf("A area do circulo com raio %f eh %f\n",radius,area);
                  break;
            }
            case 4:{
                  float com,lar,area;

                  printf("Digite o comprimento e a largura do retângulo\n");
                  scanf("%f %f",&len,&breadth);

                  area=(float)com*lar;
                  printf("A area do retângulo eh %f\n",area);
                  break;
            }
            case 5:{
                  float base,alt,area;

                  printf("Digite a base  e a altura do paralelogramo\n");
                  scanf("%f %f",&base,&alt);

                  area=(float)base*height;
                  printf("A area do paralelogramo eh %f\n",area);
                  break;
            }
            default:{
                  printf("escolha invalida\n");
                  printf("obrigado por usar nossos serviços");
                  break;
            }
      }
      return 0;
}