#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
   FILE *arq;
   int i,j;
   char texto[50];
   char maiusc[50];
   char nome_arq[20];
   int num;
   char c;
   
    printf("\n\nDigite o nome do arquivo a ser criado: ");
    scanf("%s", &nome_arq);
    scanf("%c",&c);
    arq = fopen(nome_arq, "w");
   
    if (arq == NULL) {
         fprintf(stderr,"fopen() failed in file %s at line # %d", __FILE__,__LINE__);
         exit(EXIT_FAILURE);
    }

    for (i=0; i < 2; i++){
      printf("\n\nDigite uma frase com 49 caracteres máximo: ");
      gets(texto);
      fflush(stdin);
      j=0;
      
        while ( texto[j] != '\0' && j < 49){
        maiusc[j] = toupper(texto[j]);
        j++;
      }
        maiusc[j]='\0';

        fwrite(&num, sizeof(int), 1, arq);

        fwrite(maiusc, sizeof(char), num, arq);
    }

   fclose(arq);
   arq = fopen(nome_arq, "r");
    if (arq == NULL) {
         fprintf(stderr,"fopen() failed in file %s at line # %d", __FILE__,__LINE__);
         exit(EXIT_FAILURE);
    }

    fread(&num, sizeof(int),1,arq);
    fread(texto, sizeof(char),num, arq);
    
   while (!feof (arq) ){
      printf("\n\nTexto Lido: %s", texto);
      memset(texto,'\0',50);
      fread(&num, sizeof(int),1,arq);
      fread(texto, sizeof(char),num, arq);

    }
    fclose(arq);
}
