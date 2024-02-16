#include <stdio.h>
main(){
	int a, b;
	float c;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	c = sqrt(a * a + b * b);
	printf("c: %.2f\n", c);
}