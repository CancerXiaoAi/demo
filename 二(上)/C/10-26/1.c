#include<stdio.h>
main()
{
	double x=142.437347;
	double re;
	re = x - (int)x;
	printf("��������Ϊ: %d\n", (int)x);
	printf("С������Ϊ: %lf\n", re);
	printf("����4λС��Ϊ: %.4f\n", x);
} 
