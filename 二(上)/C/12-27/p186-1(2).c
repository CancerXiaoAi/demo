#include<stdio.h>
main(){
	void printstar(n);
	//error
	int n=0;
	printf("n=%d", n);
	printstar(n);
	
}
//error
void printstar(n){
	int i;
	for(i=0;i<=n;i++){
		printf("*");
	}
}