#include<stdio.h>
main(){
	float price[10]={12.5,28.9,230,121.2,98.9,83.1,10,38.8,52,110};
	int i;
	float sum;
	for(i=0;i<sizeof(price)/sizeof(float);i++){
		sum+= price[i];
	}
	printf("总和为: %f\n", sum);
	printf("平均值为: %f\n", sum/sizeof(price)/sizeof(float));
}