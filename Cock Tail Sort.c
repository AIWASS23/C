#include <stdio.h>
#define MAX 8

int main(){
	int data[MAX];
	int i, j, n, c;

	printf("\nEntre com os dados\n");

	for (int i = 0; i < MAX; i++){
		scanf("%d", &data[i]);
	}
	n = MAX;    
	do{
		for (int i = 0;  i < n - 1; i++){
			if (data[i] > data[i + 1]){
				data[i] = data[i] + data[i + 1];
				data[i + 1] = data[i] - data[i + 1];
				data[i] = data[i] - data[i + 1];
			}
		}
		n = n - 1;

		for (int i = MAX - 1, c = 0; i >= c; i--){
			if(data[i] < data[i - 1]){
				data[i] = data[i] + data[i - 1];
				data[i - 1] = data[i] - data[i - 1];
				data[i] = data[i] - data[i - 1];
			}
		}
		c = c + 1;

	} 
	while (n != 0 && c != 0);

	printf("a estruturação dos elementos:");
	
	for (int i = 0; i < MAX; i++){
		printf("%d\t", data[i]);
	}
}

/*
Input: Enter the data
9 6 2 12 11 9 3 7
*/