#include<stdio.h>
main(){
	int a[]={80,56,83,79,91,58,64,85,90,60};
	int i;
	int j=0,k=0;
	for(i=0;i<sizeof(a)/sizeof(float);i++){
		if(a[i]==72){
			j=1;
			break;
		}
	}
	for(i=0;i<sizeof(a)/sizeof(float);i++){
		if(a[i]==85){
			k=1;
			break;
		}
	}
	if(j==0){
		printf("72没找到\n");
	}else{
		printf("72找到了\n");
	}
	if(k==0){
		printf("85没找到\n");
	}else{
		printf("85找到了\n");
	}
}