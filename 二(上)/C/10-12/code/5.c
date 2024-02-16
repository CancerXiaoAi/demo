#include <stdio.h>
main(){
	int a, b;
	double c;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	c = sqrt(pow(a, 2) + pow(b, 2));
	printf("%.2f", c);
}