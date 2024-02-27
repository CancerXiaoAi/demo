#include<stdio.h>
main(){
	int b=5, i;
	//error
	int a[5] = {1,2,3,4,5};
	for(i=0; i<b; i++){
		printf("%d ", a[i]);
	}
}