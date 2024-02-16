#include<stdio.h>
main(){
	int t;
	t=0;
	while(1){
		t++;
		printf("*");
		if(t>3){
			break;
		}
	}
}