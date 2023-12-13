#include<stdio.h>
main(){
	char strs[100]="My name is cancerai";
	int sum=0,i;
	for(i=0;i<100;i++){
		if(strs[i]==' '){
			sum++;
		}
	}
	printf("¿Õ¸ñÓÐ%d¸ö\n", sum);
}