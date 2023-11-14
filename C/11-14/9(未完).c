#include <stdio.h>
int main () {
	int grade;
	while (true){
		printf("输入1~100的整数: ");
		scanf("%d", grade);
		if(grade >= 0 && grade <= 100){
			printf("输入的数字是: %d", grade);
			break;
		}else{
			continue;
		}
	}
}