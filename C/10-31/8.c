#include <stdio.h>
main(){
	int num;
	printf("请输入一个分数: ");
	scanf("%d", &num);
	if(num >= 60)
		printf("%d", num);
}