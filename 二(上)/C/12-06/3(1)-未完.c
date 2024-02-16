#include<stdio.h>
main(){
	int score[10]={80,56,83,79,91,58,64,85,90,60};
	int i;
	int min,max;
	
	for(i=0;i<sizeof(score)/sizeof(int);i++){
		min=score[i];
		max=score[i+1];
		if(min<max){
			score[i]=min;
		}else{
			score[i]=max;
		}
	}
	for(i=0;i<sizeof(score)/sizeof(int);i++){
		printf("%d\n", score[i]);
	}
}