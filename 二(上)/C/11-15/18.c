#include <stdio.h>
int main () {
	int grade, grade1, grade2, grade3;
	printf("�������гɼ�: ");
	scanf("%d", &grade1);
	printf("����ƽʱ�ɼ�: ");
	scanf("%d", &grade2);
	printf("������ĩ�ɼ�: ");
	scanf("%d", &grade3);
	grade = grade1 * 0.3 + grade2 * 0.3 + grade3 * 0.4;
	if(grade >= 60) {
		printf("ף���㣬����ɼ������ˣ�");
	}else {
		printf("���ź�������ɼ�û�м���");
	}
}