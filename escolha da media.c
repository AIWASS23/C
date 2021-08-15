#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	
float nota1, nota2, nota3, calculo;
char tipocalculo[15];

scanf("%f",&nota1);
scanf("%f",&nota2);
scanf("%f",&nota3);
scanf("%s",tipocalculo);

if (strcmp(tipocalculo,"ARITMETICA") == 0){
calculo = (nota1 + nota2 + nota3) / 3;
printf("MEDIA ARITMETICA = %.2f\n",calculo);
}

else if (strcmp(tipocalculo,"PONDERADA") == 0){
calculo = (( nota1 * 3 ) + (nota2 * 3) + (nota3 * 4)) /10;
printf("MEDIA PONDERADA = %.2f\n",calculo);
}

else if (strcmp(tipocalculo,"HARMONICA") == 0){	
calculo = 3/(1/nota1 + 1/nota2 +1/nota3);
printf("MEDIA HARMONICA = %.2f\n",calculo);
}

return 0;	

}