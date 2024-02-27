#include <stdio.h>
main(){
	int re, a, b, c, d;
	printf("输入一个4位整数: ");
	scanf("%d", &re);
	a = re % 10;
	c = re / 100 % 10;
	b = re / 10 % 10;
	d = re /1000;
	printf("总和为: %d\n", a+b+c+d);
}