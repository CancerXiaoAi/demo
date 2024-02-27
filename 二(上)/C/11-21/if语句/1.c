#include<stdio.h>
int main () {
	float t;
	printf("输入你的体温: ");
	scanf("%f", &t);
	if (t<37.3) {
		printf("体温正常，可以进入\n");
	}
}