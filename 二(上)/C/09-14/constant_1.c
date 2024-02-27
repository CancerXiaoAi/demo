#include <stdio.h>
main(){
	int length, width, circum, area;
	length = 57;
	width = 100;
	circum = (length + width) * 2;
	area = length * width;
	printf("周长是: %d,面积是: %d", circum,area); 
}