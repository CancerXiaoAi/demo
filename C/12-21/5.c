#include<stdio.h>
void printArray(int a[]){
	int i;
	for(i=0;i<10;i++){
		printf("%d\n", a[i]);
	} 
}
main(){
	int a[10] = {60,45,100,90,45,34,49,34,78,90};
	printArray(a);
}