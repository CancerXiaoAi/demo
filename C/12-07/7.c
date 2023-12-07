#include<stdio.h>
main(){
	int b[3][3]={{1,2,3},{5,6,7},{9,10,11}};
	int i,j,sum1=0,sum2=0;
	for(i=0;i<3;i++) {
		sum1+=b[i][i];
	}
	for(i=2;i>=0;i--) {
		sum2+=b[i][i];
	}
	printf("%d\n", sum1+sum2);
}