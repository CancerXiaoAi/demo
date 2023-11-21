#include<stdio.h>
int main () {
	float t;
	char test;
	printf("输入你的体温和核算结果: (p为阳性,n为阴性): ");
	scanf("%f,%c", &t, &test);
	if (t < 37.3 && test == 'n') {
		printf("可以进入\n");
	}
	if (t >= 37.3 && test == 'n') {
		printf("居家\n");
	}
	if (t >= 37.3 && test == 'p') {
		printf("立即隔离\n");
	}
	if (t < 37.3 && test == 'p') {
		printf("立即隔离\n");
	}
}