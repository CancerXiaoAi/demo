#include <stdio.h>
int main () {
	int grade, grade1, grade2, grade3;
	printf("输入期中成绩: ");
	scanf("%d", &grade1);
	printf("输入平时成绩: ");
	scanf("%d", &grade2);
	printf("输入期末成绩: ");
	scanf("%d", &grade3);
	grade = grade1 * 0.3 + grade2 * 0.3 + grade3 * 0.4;
	if(grade >= 60) {
		printf("祝贺你，这个成绩及格了！");
	}else {
		printf("很遗憾，这个成绩没有及格");
	}
}