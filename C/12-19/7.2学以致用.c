#include<stdio.h>
main () {
	float a, b;
	printf("输入实数a: ");
	scanf("%f", &a);
	printf("输入实数b: ");
	scanf("%f", &b);
	printf("两数之和是: %f", sum(a, b));
}
int sum (float a, float b) {
	return a + b;
}