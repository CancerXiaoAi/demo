#include <stdio.h>
main(){
	int a, b, y;
	a = -10;
	b = 30;
	y = (a * a + b * b) / (float)(a + b);
	printf("%d\n", y);
} 