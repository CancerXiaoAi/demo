#include<stdio.h>
main () {
	float sum (float a, float b);
	float a, b;
	printf("输入实数a: ");
	scanf("%f", &a);
	printf("输入实数b: ");
	scanf("%f", &b);
	printf("两数之和是: %f", sum(a, b));
}
float sum (float a, float b) {
	return a + b;
}