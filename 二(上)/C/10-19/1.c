#include <stdio.h>
#include <stdlib.h>
main(){
	int x, y, z;
	printf("\t����������ľ���ֵ\n\n");
	printf("�������һ����: ");
	scanf("%d", &x);
	printf("������ڶ�����: ");
	scanf("%d", &y);
	z = abs(x - y);
	printf("\n\n���: |%d-%d|=%d\n", x, y, z);
}