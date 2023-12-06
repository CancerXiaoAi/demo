#include<stdio.h>
main(){
	int score[10]={80,56,83,79,91,58,64,85,90,60};
	int i;
	int min,max;
	min=score[0];
	max=score[0];
	for(i=0;i<sizeof(score)/sizeof(int);i++){
		if(score[i]<min){
			min=score[i];
		}
		score[i]=min;
		i--;
	}

	printf("max: %d\n", max);
	printf("min: %d\n", min);
}