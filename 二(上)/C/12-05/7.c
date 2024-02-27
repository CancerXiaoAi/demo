#include<stdio.h>
main(){
	int a[5];
	int i;
	printf("输入5个整数: ");
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		scanf("%d", &a[i]);
	}
	printf("a[4]是:\n");
	printf("%d\n", a[4]);
	printf("数组中的第一个数据是:\n");
	printf("%d\n", a[0]);
}