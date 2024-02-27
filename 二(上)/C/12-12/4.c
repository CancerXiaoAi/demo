#include<stdio.h>
main () {
	int a[]={80,56,83,79,91,58,64,85,90,60};
	int i,min,max;
	min=max=a[0];
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		if(a[i]<min){
			min=a[i];
		}
		if(a[i]>max){
			max=a[i];
		}
	}
	printf("min: %d\n", min);
	printf("max: %d\n", max);
}