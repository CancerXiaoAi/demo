#include<stdio.h>
float max2(float a, float b){
	int m;
	if(a>b){
		m=a;
	}
	if(b>a){
		m=b;
	}
	return m;
}
float max1(float a, float b, float c, float	d){
	int m, m2;
	if(a>b){
		m=a;
	}
	if(b>a){
		m=b;
	}
	m2 = max2(c, d);
	if(m>m2){
		return m;
	}else{
		return m2;
	}
}
main (){
	float a, b, c, d, re;
	printf("input number a: ");
	scanf("%f", &a);
	printf("input number b: ");
	scanf("%f", &b);
	printf("input number c: ");
	scanf("%f", &c);
	printf("input number d: ");
	scanf("%f", &d);
	printf("max: %f", max1(a, b, c, d));
} 