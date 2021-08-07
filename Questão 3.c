#include <stdio.h>

int main(){
	int i,j;
	int matriz[5][5];
	
	for(int i=0;i<=5;i=i+1){
		for(int j=0;j<=5;j=j+1){
		   if(i!=j){printf("|0|",matriz[i][j]);}	
			if(i==0&&j==0){printf("|10|",matriz[0][0]);}
			if(i==1&&j==1){printf("|1|",matriz[1][1]);}
			if(i==2&&j==2){printf("|4|",matriz[2][2]);}
			if(i==3&&j==3){printf("|-1|",matriz[3][3]);}
			if(i==4&&j==4){printf("|-7|",matriz[4][4]);}
			if(i==5&&j==5){printf("|8|",matriz[5][5]);}
      }
      printf("\n");
   }
	return 0;
}
