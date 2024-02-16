#include<stdio.h>
void countArray(int a[]){
	int sum=0;
	int i;
	for(i=0;i<10;i++){
		sum+=a[i];
	}
	printf("sum: %d\n", sum);
	printf("avrage: %f\n", (float)(sum/10));
}
void printArray(int a[]){
	int i;
	for(i=0;i<10;i++){
		printf("%d,", a[i]);
	}
}
main (){
	int a[10]={80,56,83,79,91,58,64,85,90,60};
	countArray(a);
	printArray(a);
} 