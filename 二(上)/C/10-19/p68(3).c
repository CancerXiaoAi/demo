#include <stdio.h>
main(){
	int a, b;
	float re;
	printf("请输入第一个整数: ");
	scanf("%d", &a);
	printf("请输入第二个整数: ");
	scanf("%d", &b);
	re = a / b;
	re = (int)10*re+0.5;
	re = re / 10;
	printf("%d除以%d=%.2f\n", a, b, re);
	printf("%d模与%d=%d\n", a, b, a % b);
	
}