#include<stdio.h>
main(){
	float price[10]={12.5,28.9,230,121.2,98.9,83.1,10,38.8,52,110};
	int i;
	float sum,min,max;
	min=price[0];
	max=price[0];
	for(i=0;i<sizeof(price)/sizeof(float);i++){
		if(price[i]>max){
			max=price[i];
		}
		if(price[i]<min){
			min=price[i];
		}
	}
	printf("max: %.2f\n", max);
	printf("min: %.2f\n", min);
}