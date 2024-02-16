#include<stdio.h>
main(){
	int max(int a[]);
	int a[10];
	int i;
	for (i=0;i<10;i++){
		printf("µÚ%d´ÎÊäÈë: ", i+1);
		scanf("%d", &a[i]);
	}
	printf("max: %d", max(a));
}
int max(int a[]) {
	int i, j, max=a[0];
	for (i=0;i<10;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}