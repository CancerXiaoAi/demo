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
		if(a[i]>=60){
			sum++;
		}
	}
	printf("及格的科目数为: %d\n", sum);
}