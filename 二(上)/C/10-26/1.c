#include<stdio.h>
main()
{
	double x=142.437347;
	double re;
	re = x - (int)x;
	printf("整数部分为: %d\n", (int)x);
	printf("小数部分为: %lf\n", re);
	printf("保留4位小数为: %.4f\n", x);
} 
