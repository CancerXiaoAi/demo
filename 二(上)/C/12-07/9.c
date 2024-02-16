#include<stdio.h>
main(){
	int score[4][3]={{81,76,90},{94,90,85},{78,65,58},{79,83,70}};
	int i,j;
	printf("大学语文\t高等数学\tC语言\n");
	for(i=0;i<4;i++) {
		for(j=0;j<3;j++) {
			printf("%d\t\t", score[i][j]);
		}
		printf("\n");
	}
}