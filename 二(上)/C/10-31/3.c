#include <stdio.h>
main(){
	int num;
	printf("������һ������: ");
	scanf("%d", &num);
	if(num % 3 == 0)
		printf("%d", num);
	else
		printf("��������ֲ��ܱ�3����\n");
}