#include <stdio.h>
int main () {
	int time, pay, rate;
	printf("���빤��ʱ��(Сʱ): ");
	scanf("%d", &time);
	if(time > 160) {
		pay = 25 * time;
	}else {
		pay = 20 * time;
	}
	printf("Ӧ�õĹ���Ϊ: %d\n", pay);
}