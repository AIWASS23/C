#include <stdio.h> 
#include <conio.h>
 
int  main() { 
	int a, b, c = 0;

	printf("calculo de operações binarias entre 2 numeros. Digite dois numeros:");
	scanf("%d", &a);
	scanf("%d", &b);

	clrscr();
	
	c = a & b;
	printf( "\n a & b = %d", c );
	
	c = a | b;
	printf( "\n a | b = %d", c );
	
	c = a ^ b;
	printf( "\n a ^ b = %d", c );
	
	c = ~a;
	printf( "\n ~a = %d", c );
	
	c = a << b;
	printf( "\n a << b = %d", c );
	
	c = b >> a;
	printf( "\n b >> a = %d", c );
	
	getch();
	return 0;
}