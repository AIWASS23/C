#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  
  int tamanho,cont,i,j;
     
     printf("Insira o numero de valores conhecidos da funcao que deseja interpolar:\t");
     scanf("%d",&tamanho);
     printf("\n"); 
     
  float vetfx[tamanho],vetx[tamanho],x,pdtparcial,pdtfinal,fx;
     
     printf("Valores de x pre existentes:\n");
     
     for(cont=0;cont<tamanho;cont++){
        printf("Insira o valor de x%d :\t",cont);
        scanf("%f",&vetx[cont]);
     }                                
     printf("\n");   
        
          
     printf("Valores de f<x> pre existentes:\n");    
     
     for(cont=0;cont<tamanho;cont++){
        printf("Insira o valor de y%d :\t",cont);
        scanf("%f",&vetfx[cont]);
     }                                
     printf("\n");   

     printf("Insira o valor de x para o qual deseja obter f<x>: ");
     scanf("%f",&x);
     printf("\n");
     
     fx=0;        
     pdtfinal=1;
          
     for(i=0;i<tamanho;i++){
       for(j=0;j<=tamanho;j++){
          if(j==i){j++;}
          pdtparcial=0;
          
          pdtparcial=(x-vetx[j])/(vetx[i
          ]-vetx[j]);          
          
          if(j!=tamanho){ pdtfinal*=pdtparcial; }

       }
       
       fx=fx+vetfx[i]*pdtfinal;
        
      // pdtfinal=0;                                            
       pdtfinal=1;                                            
     } 

     printf("O valor de f<%f> e : %.4f ",x,fx);
     printf("\n\n");
     

  system("PAUSE");    
  return 0;
}
