#include <stdio.h>
main(){
	int re, a, b, c, d;
	printf("����һ��4λ����: ");
	scanf("%d", &re);
	a = re % 10;
	c = re / 100 % 10;
	b = re / 10 % 10;
	d = re /1000;
	printf("�ܺ�Ϊ: %d\n", a+b+c+d);
}