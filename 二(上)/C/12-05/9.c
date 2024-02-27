#include<stdio.h>
main(){
	int a[5];
	int i;
	int sum=0;
	int min, max;
	printf("输入5个整数: ");
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		scanf("%d", &a[i]);
	}
	min=a[0];
	max=a[0];
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		if(a[i]<min){
			min=a[i];
		}
		if(a[i]>max){
			max=a[i];
		}
	}
	printf("最低分为: %d\n", min);
	printf("最高分为: %d\n", max);
}