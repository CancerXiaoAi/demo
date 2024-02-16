#include <stdio.h>
#include <stdlib.h>
main(){
	int x, y, z;
	printf("\t求两个数差的绝对值\n\n");
	printf("请输入第一个数: ");
	scanf("%d", &x);
	printf("请输入第二个数: ");
	scanf("%d", &y);
	z = abs(x - y);
	printf("\n\n结果: |%d-%d|=%d\n", x, y, z);
}