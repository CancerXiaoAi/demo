#include<stdio.h>
main(){
	//error
	float sum(float x, float y);
	float a, b, s;
	scanf("%f%f", &a, &b);
	s=sum(a, b);
	printf("sum=%f", s);
}
//error
float sum(float x, float y){
	float s;
	s=x+y;
	return s;
}