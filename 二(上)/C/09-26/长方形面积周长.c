#include <stdio.h>
main(){
	int width, height, c, s;
	printf("�����:");
	scanf("%d", &width);
	printf("�����:");
	scanf("%d", &height);
	c = (width + height) * 2;
	s = width * height;
	printf("���Ϊ: %d\n�ܳ�Ϊ: %d", c, s); 
}