#include<stdio.h>
main (){
	int a,b,c,d,e,sum;
	printf("输入5个整数，用逗号隔开: ");
	scanf("%d,%d,%d,%d,%d", &a,&b,&c,&d,&e);
	printf("和为: %d", a+b+c+d+e);
	printf("平均数为: %d", (a+b+c+d+e) / 5);
}