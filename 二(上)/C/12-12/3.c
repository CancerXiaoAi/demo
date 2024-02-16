#include<stdio.h>
main () {
	int a[]={80,56,83,79,91,58,64,85,90,60};
	int i,sum=0;
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		sum+=a[i];
	}
	printf("和为: %d\n", sum);
	printf("平均值为: %d\n", sum/(sizeof(a)/sizeof(int)));
}