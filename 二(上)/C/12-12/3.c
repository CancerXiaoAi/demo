#include<stdio.h>
main () {
	int a[]={80,56,83,79,91,58,64,85,90,60};
	int i,sum=0;
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		sum+=a[i];
	}
	printf("��Ϊ: %d\n", sum);
	printf("ƽ��ֵΪ: %d\n", sum/(sizeof(a)/sizeof(int)));
}