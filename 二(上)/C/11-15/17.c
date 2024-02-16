#include <stdio.h>
int main () {
	int time, pay, rate;
	printf("输入工作时间(小时): ");
	scanf("%d", &time);
	if(time > 160) {
		pay = 25 * time;
	}else {
		pay = 20 * time;
	}
	printf("应得的工资为: %d\n", pay);
}