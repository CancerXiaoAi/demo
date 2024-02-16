#include <stdio.h>
main(){
	int a = 2, b = 3;
	float x = 3.9, y = 2.3;
	float r;
	r = (float)(a + b) / 2 + (int)x % (int)y;
	printf("%f\n", r);
} 