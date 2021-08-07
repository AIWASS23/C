#include <stdio.h>
#include <stdlib.h>

void adicao(){
     float x, y, total;
     char sn;
     do{
     system("cls");
     printf("OBS: DIGITE -0 PARA SAIR\n");
     printf("Digite a primeira parcela:\n");
     scanf("%f", &x);
     if (x != -0){
           printf("+\n");
           scanf("%f", &y);
           total = x+y;
           printf("=\n");
           printf("%.2f\n", total);
          // getch();
           }
     else{
           int main();                                       
           }
           }while (x != -0);
           }
void subtracao(){
     float x, y, total;
     char sn;
     do{
                 system("cls");
                 printf("OBS: DIGITE -0 PARA SAIR\n");
                 printf("Digite a primeira parcela:\n");
                 scanf("%f", &x);
                 if (x != -0){ 
                       printf("-\n");
                       scanf("%f", &y);
                       total = x-y;
                       printf("=\n");
                       printf("%.2f\n", total);
                       //getch();
                       }
                 else{
                      int main();                                        
                      }
                      }while (x != -0);
                      }
void multiplicacao(){
     float x, y, total;
     char sn;
     do{
     system("cls");
     printf("OBS: DIGITE -0 PARA SAIR\n");
     printf("Digite o primeiro fator:\n");
     scanf("%f", &x);
     if (x != -0){
           printf("x\n");
           scanf("%f", &y);
           total = x*y;
           printf("=\n");
           printf("%.2f\n", total);
           //getch();
           }
     else{
           main();                                        
           }
           }while (x != -0);
           }
void divisao(){
     float x, y, total;
     char sn;
     do{
     system("cls");
     printf("OBS: DIGITE -0 PARA SAIR\n");
     printf("Digite a primeira parcela:\n");
     scanf("%f", &x);
     if (x != -0){
           printf("/\n");
           scanf("%f", &y);
           total = x/y;
           printf("=\n");
           printf("%.2f\n", total);
           getch();
           adicao();
           }
     else{
           main();                                     
           }
           }while (x != -0);
           }
void menu(){
     int opcao;
     system("cls");
     printf("MENU\n");
     printf("1-Adicao\n");
     printf("2-Subtracao\n");
     printf("3-Multiplicacao\n");
     printf("4-Divisao\n");
     printf("5-Sair\n");
     printf(">>");
     scanf("%d", &opcao);
     switch (opcao){
            case 1:
                 adicao();
                 break;
            case 2:
                 subtracao();
                 break;
            case 3:
                 multiplicacao();
                 break;
            case 4:
                 divisao();
                 break;
            default:
                    system("exit");}}
main(){
       printf("|||||||||||||||\n");
       printf("||CALCULADORA||\n");
       printf("||MARCELO||\n");
       printf("|||||||||||||||\n");
       menu();
       }
     
                      
