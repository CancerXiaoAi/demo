#include<stdio.h>
main () {
	int a[]={80,56,83,79,91,58,64,85,90,60};
	int i,j;
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
	printf("≈≈–Ú∫Û: \n");
	for(i=0;i<10;i++){
		printf("%d\n", a[i]);
	}
}