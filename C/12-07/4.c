#include<stdio.h>
main(){
	float a[]={12.5,28.9,230,121.2,98.9,83.1,10,38.8,52,110,100,80,56,83,79,91,58,64,85,90,60};
	int i;
	int j=0;
	for(i=0;i<sizeof(a)/sizeof(float);i++){
		if(a[i]==102){
			j=1;
			break;
		}
	}
	if(j==0){
		printf("没找到\n");
	}else{
		printf("找到了\n");
	}
}