#include <stdio.h>
int main (){
	int smark;
	printf("����1~100֮��ĳɼ�: ");
	scanf("%d", &smark);
	if(smark < 60){
		printf("�ȼ�ΪE\n");
	}else if (smark >= 60 && smark < 70){
		printf("�ȼ�ΪD\n");
	}else if (smark >= 70 && smark < 80){
		printf("�ȼ�ΪC\n");
	}else if (smark >= 80 && smark < 90){
		printf("�ȼ�ΪB\n");
	}else if (smark >= 90 && smark < 100){
		printf("�ȼ�ΪA\n");
	}
}