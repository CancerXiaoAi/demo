#include<stdio.h>
void inputArray(){
	int i;
	int a[10];
	for(i=0;i<10;i++){
		printf("input a number: ");
		scanf("%d", &a[i]);
	}
}
main(){
	inputArray();
	printf("DONE\n");
}