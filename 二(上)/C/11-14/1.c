#include <stdio.h>
#define PI 3.14
int main () {
	int r;
	float re;
	printf("请输入半径: ");
	scanf("%d", &r);
	if( r > 0) {
		re = 2 * PI * r;
		printf("圆的周长为: %f", re);
	}
}