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
		printf("72û�ҵ�\n");
	}else{
		printf("72�ҵ���\n");
	}
	if(k==0){
		printf("85û�ҵ�\n");
	}else{
		printf("85�ҵ���\n");
	}
}