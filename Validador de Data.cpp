#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Declara a função validaData ao programa
int ValidarData (int dia, int mes, int ano);

int main()
{
    
  int dd1, mm1, aa1, opc;
  
  opc=1; 
  while (opc==1) {
        
      printf("Informe uma data dia/mes/ano\n");
      scanf("%d/%d/%d", &dd1,&mm1,&aa1);
      
      if (ValidarData (dd1, mm1, aa1)==0) {    
         printf("Data valida\n");
      }
      else {
         printf("Data Invalida\n");
      }
  
      getch ();
      
      opc=0;
      printf ("tecle (1) para continuar ou (2) para sair\n");
      while ((opc!=1)&&(opc!=2)) {
      scanf ("%d", &opc);
           if ((opc!=1)&&(opc!=2)) {
                printf ("Opcao Invalida\n");
           }
      }
      
      //Limpa tela
      system ("cls");
   
  }
  
  printf ("***Programa encerrado!***\n");
  system ("pause");
  
}

//Essa função recebe três valores inteiros e retorna um inteiro
//Se retorna 0 indica que a data é válida, se retorna 1 indica que a data é inválida
int ValidarData (int dia, int mes, int ano)
{
int resto, tipo;
    //Verifica os meses que tem 31 dias
    if ((mes==01) || (mes==03) || (mes==05) || (mes==07) || (mes==8) || (mes==10) || (mes==12)) {
              //Se o dia for maior que 31 OU menor que 1 OU ano maior que 9999 OU menor que 0000 a data é inválida
              if ((dia>31) || (dia<1) || (ano>9999) || (ano<0000)) {
                       tipo=1;
              }
              else {
                   tipo=0;
    }         }
    else {
         //Verifica os meses que tem 30 dias
         if ((mes==04) || (mes==06) || (mes==9) || (mes==11)) {
                   //Se o dia for maior que 30 OU menor que 1 OU ano maior que 9999 OU menor que 0000 a data é inválida
                   if ((dia>30) || (dia<1) || (ano>9999) || (ano<0000)) {
                       tipo=1;
                   }
                   else {
                        tipo=0;
         }         }
         else {
              if (mes==2) {
                          //Se o resto for 0, isso indica que o ano é bisexto, sendo assim o mês de Fevereiro terá 29 dias
                          resto=(ano%4);
                          if (resto==0) {
                                        //Se o dia for maior que 29 OU menor que 1 OU ano maior que 9999 OU menor que 0000 a data é inválida
                                        if ((dia>29) || (dia<1) || (ano>9999) || (ano<0000)) {
                                           tipo=1;                                                 
                                        }
                                        else {
                                             tipo=0;
                                        }
                          }
                          //Se não for ano bisexto, o mês de Fevereiro terá 28 dias
                          else {
                               //Se o dia for maior que 28 OU menor que 1 OU ano maior que 9999 OU menor que 0000 a data é inválida
                               if ((dia>28) || (dia<1) || (ano>9999) || (ano<0000)) {
                                  tipo=1;
                               }
                               else {
                                    tipo=0;
                               }
                          }
              }
              //Se o mês não estiver entre 1 e 12 a data é inválida
              else {
                   tipo=1;
              }
         }
    }    
    
    return (tipo);

}
