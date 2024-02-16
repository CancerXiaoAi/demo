#include<stdio.h>
main(){
	int a[]={1,2,3,4,5};
	int i;
	for(i=sizeof(a)/sizeof(int)-1;i>=0;i--){
		printf("%d\n", a[i]);
	}
}