#include <stdio.h>
main(){
	int num;
	printf("请输入一个整数: ");
	scanf("%d", &num);
	if(num % 3 == 0 && num % 5 == 0)
		printf("%d", num);
}