#include<stdio.h>
main(){
	float a[]={12.5,28.9,230,121.2,98.9,83.1,10,38.8,52,110,100,80,56,83,79,91,58,64,85,90,60};
	int i;
	float min,max;
	min=max=a[0];
	for(i=0;i<sizeof(a)/sizeof(float);i++){
		if(a[i]<min){
			min=a[i];
		}
		if(a[i]>max){
			max=a[i];
		}
	}
	printf("min: %f\n", min);
	printf("max: %f\n", max);
}