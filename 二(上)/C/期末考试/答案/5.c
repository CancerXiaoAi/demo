#include <stdio.h>
main() {
	float a,b;
	int y;
	printf("input two integers: ");
	scanf("%f %f", &a, &b);
	if(a>b){
		y=2;
	}
	if(a==b){
		y=1;
	}
	if(a<b){
		y=0;
	}
	printf("y=%d\n", y);
}