#include <stdio.h>
#define PI 3.1415926
main(){
	float r, circum, area;
	r = 2.0;
	circum = 2 * PI * r;
	area = PI * (r * r);
	printf("�ܳ���: %f,�����: %f", circum, area);
}