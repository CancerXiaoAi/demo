#include <stdio.h>
main(){
	int a, b, c;
	double s, area;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	s = (a + b + c) / 2;
	area = sqrt((s - a) * (s - b) * (s - c) * s);
	printf("三角形的面积为: %f\n", area);
}