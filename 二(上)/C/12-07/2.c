#include<stdio.h>
main(){
	float a[]={12.5,28.9,230,121.2,98.9,83.1,10,38.8,52,110,100,80,56,83,79,91,58,64,85,90,60};
	int i;
	float sum=0;
	for(i=0;i<sizeof(a)/sizeof(float);i++){
		sum+=a[i];
	}
	printf("和为: %f\n", sum);
	printf("平均值为: %f\n", sum/(sizeof(a)/sizeof(float)));
}