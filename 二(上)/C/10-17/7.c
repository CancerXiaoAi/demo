#include <stdio.h>
main(){
	int x;
	float y1, y2;
	printf("ÊäÈëxµÄÖµ: ");
	scanf("%f", &x);
	y1 = 2.4 * x - 1 / 2;
	y2 = x % 2/5-x;
	printf("y1: %f", y1);
	printf("y2: %f", y2);
}