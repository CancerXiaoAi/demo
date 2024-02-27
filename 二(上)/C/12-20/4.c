#include<stdio.h>
float max(float a, float b, float c){
	int max;
	if(a>b && a>c){
		max=a;
	}
	if(b>a && b>c){
		max=b;
	}
	if(c>a && c>b){
		max=c;
	}
	return max;
}
main (){
	float a, b, c;
	printf("input number a: ");
	scanf("%f", &a);
	printf("input number b: ");
	scanf("%f", &b);
	printf("input number c: ");
	scanf("%f", &c);
	printf("max: %f", max(a, b, c));
} 