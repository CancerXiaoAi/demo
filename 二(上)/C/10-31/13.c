#include <stdio.h>
main(){
	int mark;
	printf("�������: ");
	scanf("%d", &mark);
	if(mark<60)
		printf("�ȼ�Ϊ: E\n");
	if(mark >= 60 && mark <70)
		printf("�ȼ�Ϊ: D\n");
	if(mark >= 70 && mark <80)
		printf("�ȼ�Ϊ: C\n");
	if(mark >= 80 && mark <90)
		printf("�ȼ�Ϊ: B\n");
	if(mark >= 90 && mark <100)
		printf("�ȼ�Ϊ: A\n");
}