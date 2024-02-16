#include <stdio.h>
#define PI 3.1415926
main(){
	float r, circum, area;
	r = 2.0;
	circum = 2 * PI * r;
	area = PI * (r * r);
	printf("周长是: %f,面积是: %f", circum, area);
}