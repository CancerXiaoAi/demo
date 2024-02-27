#include<stdio.h>
float addTest(float a, float b){
	return a+b;
}
main (){
	float a, b;
	printf("input number a: ");
	scanf("%f", &a);
	printf("input number a: ");
	scanf("%f", &b);
	printf("sum: %f\n", addTest(a, b));
} 