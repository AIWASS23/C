#include <stdio.h>

void main(){
   int x = 10;
   if(x == 10){
      printf("X igual a 10");
   } else {
     printf("X diferente de 10");
      }

   switch(x){
      case 10:
         printf("X igual a 10");
         break;

      case 20:
         printf("X igual a 20");
         break;
 
      default:
         printf("X diferente de 10");
         break;
   }
}






