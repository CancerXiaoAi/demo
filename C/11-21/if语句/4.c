#include<stdio.h>
int main () {
	int t;
	printf("����ͣ����Сʱ��(����): ");
	scanf("%d", &t);
	if(t < 2) {
		printf("�շ�5Ԫ");
	}else {
		printf("%d", 5 + (t - 2) * 2);
	}
}