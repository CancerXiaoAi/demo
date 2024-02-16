#include <stdio.h>
int main (){
	int smark;
	printf("输入1~100之间的成绩: ");
	scanf("%d", &smark);
	if(smark < 60){
		printf("等级为E\n");
	}else if (smark >= 60 && smark < 70){
		printf("等级为D\n");
	}else if (smark >= 70 && smark < 80){
		printf("等级为C\n");
	}else if (smark >= 80 && smark < 90){
		printf("等级为B\n");
	}else if (smark >= 90 && smark < 100){
		printf("等级为A\n");
	}
}