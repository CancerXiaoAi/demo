#include <stdio.h>
#include <math.h>
main(){
	int a, b, c;
	float d, x1, x2;
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b); 
	printf("c = ");
	scanf("%d",&c); 
	d = sqrt(b * b - 4 * a * c);
	x1 = (-b + d) / (2 * a);
	x2 = (-b - d) / (2 * a);
	printf("x1��ֵΪ: %f\nx2��ֵΪ: %f", x1, x2);
}