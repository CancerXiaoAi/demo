#include<stdio.h>
main(){
	int a[5];
	int i;
	int sum=0;
	printf("输入5个整数: ");
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		sum += a[i];
	}
	printf("总和为: %d\n", sum);
	printf("平均分为: %d\n", sum/(sizeof(a)/sizeof(int)));
}