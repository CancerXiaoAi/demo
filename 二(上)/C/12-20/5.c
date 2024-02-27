#include<stdio.h>
float sum(float a, float b, float c){
	return a+b+c;
}
main (){
	float a, b, c;
	printf("input number a: ");
	scanf("%f", &a);
	printf("input number b: ");
	scanf("%f", &b);
	printf("input number c: ");
	scanf("%f", &c);
	printf("sum: %f", sum(a, b, c));
} 