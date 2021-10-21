#include <stdio.h>
#include <string.h>
#include <conio.h>
void main(){
	char name[10][8], tname[10][8], temp[8];
	int i, j, n;

	printf("digite um valor pra n \n");
	scanf("%d", &n);

	printf("digite %d palavras ", n);
	for (int i = 0; i < n; i++){
		scanf("%s", name[i]);
		strcpy(tname[i], name[i]);
	}
	for (int i = 0; i < n - 1 ; i++){
		for (int j = i + 1; j < n; j++){
			if (strcmp(name[i], name[j]) > 0){
				strcpy(temp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], temp);
			}
		}
	}
	for (int i = 0; i < n; i++){
		printf("%s\t\t%s\n", tname[i], name[i]);
	}

	printf("palavras organizadas\n");
	getch();
}