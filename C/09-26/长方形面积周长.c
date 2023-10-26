#include <stdio.h>
main(){
	int width, height, c, s;
	printf("输入宽:");
	scanf("%d", &width);
	printf("输入高:");
	scanf("%d", &height);
	c = (width + height) * 2;
	s = width * height;
	printf("面积为: %d\n周长为: %d", c, s); 
}