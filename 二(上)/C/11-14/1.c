#include <stdio.h>
#define PI 3.14
int main () {
	int r;
	float re;
	printf("������뾶: ");
	scanf("%d", &r);
	if( r > 0) {
		re = 2 * PI * r;
		printf("Բ���ܳ�Ϊ: %f", re);
	}
}