#include <stdio.h>
int main () {
	int grade;
	while (true){
		printf("����1~100������: ");
		scanf("%d", grade);
		if(grade >= 0 && grade <= 100){
			printf("�����������: %d", grade);
			break;
		}else{
			continue;
		}
	}
}