include <stdio.h>
include <stdlib.h>

int main(){
  int i, j, linha, col, x;
  int flag=1;

  printf("Digite o numero de linhas\n");
  scanf("%d",&linha);

  printf("digite o numero de colunas\n");
  scanf("%d",&col);

  int a1[linha][col];
  int a2[linha][col];
  int diff[linha][col];

  printf("Entre com a primeira matrix1\n");

  for(int i = 0; i < linha; i++){
    for(int j = 0; j < col; j++){
      scanf("%d",&a1[i][j]);
    }
  }
  do{
    printf("Entre co a segunda Matrix2\n");

    for(int i = 0;i < linha; i++){
      for(int j = 0; j < col; j++){
      scanf("%d",&a2[i][j]);
      }
    }
  
    for(nt i = 0; i < linha; i++){
      for(j=0;j<col;j++){
        diff[i][j]=a2[i][j]-a1[i][j];
      }
    }

    for(int i = 0; i < linha; i++){
      for(j=0;j<col;j++){
        printf("%d\t",diff[i][j]);
      }
      printf("\n");
    }

    printf("Digite 1 para continuar a subtrair o valor acima de outra matriz, caso contrário 0 \n ");
    scanf("%d", &x);

    if(x==1){
      flag=1;

      for(int i = 0; i < linha; i++){
        for(int j = 0; j < col; j++){
          a1[i][j]=diff[i][j];
          diff[i][j]=0;
        }
      }
    }
    else{
      flag=0;
    }
  }
  while(flag);
  printf("Diferença eh:\n");

  for(int i = 0; i < linha; i++){
    for(int j = 0; j < col; j++){
      printf("%d\t",diff[i][j]);
    }
    printf("\n");
  }
}