#include<stdio.h>
main () {
	float a, b;
	printf("����ʵ��a: ");
	scanf("%f", &a);
	printf("����ʵ��b: ");
	scanf("%f", &b);
	printf("����֮����: %f", sum(a, b));
}
int sum (float a, float b) {
	return a + b;
}