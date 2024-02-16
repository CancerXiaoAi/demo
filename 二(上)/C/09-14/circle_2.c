#include <stdio.h>
main(){
	float r, circum, area, pi;
	pi = 3.1415926;
	r = 2.0;
	circum = 2 * pi * r;
	area = pi * (r * r);
	printf("周长是: %f,面积是: %f", circum, area);
}