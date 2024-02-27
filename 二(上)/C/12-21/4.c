#include<stdio.h>
void sortArray(int a[]){
	int i, j;
	int temp;
	for(i=0;i<10;i++){
		for(j=0;j<10-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<10;i++){
		printf("%d\n", a[i]);
	} 
}
main(){
	int a[10] = {60,45,100,90,45,34,49,34,78,90};
	sortArray(a);
}