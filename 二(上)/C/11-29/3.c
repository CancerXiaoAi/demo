#include<stdio.h>
main () {
	int arr[5];
	int i,sum=0,a,j;
	int min,max;
	for(i=0;i<5;i++) {
		printf("ÊäÈëµÚ%d¸ö: ", i+1);
		scanf("%d", &arr[i]);
	}
	min=max=arr[0];
	//printf("%d\n%d\n",min,max);
	for(j=0;j<=5;j++) {
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	printf("%d\n%d\n",min,max);
}