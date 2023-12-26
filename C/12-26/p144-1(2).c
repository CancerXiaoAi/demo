#include<stdio.h>
main(){
	//error
	int a[11];
	int i, sum;
	for(i=0; i<=10; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	printf("sum=%d", sum);
}