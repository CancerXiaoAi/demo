#include <stdio.h>
main(){
	int a, b;
	float re;
	printf("�������һ������: ");
	scanf("%d", &a);
	printf("������ڶ�������: ");
	scanf("%d", &b);
	re = a / b;
	re = (int)10*re+0.5;
	re = re / 10;
	printf("%d����%d=%.2f\n", a, b, re);
	printf("%dģ��%d=%d\n", a, b, a % b);
	
}