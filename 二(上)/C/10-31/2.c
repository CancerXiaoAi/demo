#include <stdio.h>
main(){
	int num;
	printf("������һ������: ");
	scanf("%d", &num);
	if(num % 2 == 0)
		printf("%d", num);
	else
		printf("��������ֲ��ܱ�2����\n");
}