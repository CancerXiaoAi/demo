#include<stdio.h>
main(){
	char ch[3][8]={"Tom","Rose","Jim"};
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<8;j++){
			printf("%c", ch[i][j]);
		}
		printf("\n");
	}
}