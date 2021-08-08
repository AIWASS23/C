#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    FILE *X;
    char P;


X = fopen("arq.txt", "w");
if (X == NULL) {
 fprintf(stderr,"\nfopen() failed in file %s at line # %d", __FILE__,__LINE__);
 exit(EXIT_FAILURE);
}
printf("\nEntre com um caracter qualquer ou 0 para terminar:");
P = getchar();
fflush(stdin); 
while (P != '0')
{
   fputc(P,X);
   printf("\nEntre com um caracter qualquer ou 0 para terminar:");
   P = getchar();
   fflush(stdin); 
}
fclose(X);
X = fopen("arq.txt", "r");
if (X == NULL){
	
   fprintf(stderr,"\nfopen() failed in file %s at line # %d", __FILE__,__LINE__);
   exit(EXIT_FAILURE);
}
printf("\n\nVou ler e mostrar o texto gravado....\n\n");
P = fgetc(X);
while (P != EOF){
	
   printf("%c",P);
   P =fgetc(X);
}

fclose(X);

}