#include<stdio.h>
main(){
	int a[10]={0,1,2,3,4};
	int i;
	printf("%d\n", a[2]);
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d\n", a[i]);
	}
}