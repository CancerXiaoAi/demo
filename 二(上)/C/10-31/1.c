#include <stdio.h>
main(){
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	if(num>=0)
		printf("%d", num);
	else
		printf("输入的整数不是非负数\n");
}