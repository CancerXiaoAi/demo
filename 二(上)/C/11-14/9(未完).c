#include <stdio.h>
int main () {
	int grade;
	printf("����1~100������: ");
	scanf("%d", &grade);
	while (grade < 0 && grade > 100){
		printf("����1~100������: \n");
		scanf("%d", &grade);
	}
	printf("�����������: %d\n", grade);
}