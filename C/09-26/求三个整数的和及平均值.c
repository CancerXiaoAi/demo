#include <stdio.h>
main(){
	int int1, int2, int3, add;
	float avg;
	printf("�������һ������:");
	scanf("%d", &int1);
	printf("������ڶ�������:");
	scanf("%d", &int2);
	printf("���������������:");
	scanf("%d", &int3);
	add = int1 + int2 + int3;
	avg = add / 3;
	printf("���ǵĺ�Ϊ: %d\nƽ��ֵΪ: %f\n", add, avg);
}