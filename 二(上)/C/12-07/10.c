#include<stdio.h>
main(){
	int score[4][3]={{81,76,90},{94,90,85},{78,65,58},{79,83,70}};
	int i,j,input,sum=0;
	for(i=0;i<4;i++) {
		for(j=0;j<3;j++) {
			scanf("%d", &input);
			score[i][j]=input;
		}
	}
	printf("大学语文\t高等数学\tC语言\n");
	for(i=0;i<4;i++) {
		for(j=0;j<3;j++) {
			printf("%d\t\t", score[i][j]);
		}
		printf("\n");
	}
	for(j=0;j<3;j++) {
		sum+=score[0][j];
	}
	printf("成绩为: %d", sum);
	sum=0;
}