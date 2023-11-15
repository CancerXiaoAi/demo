#include <stdio.h>
int main () {
	int m;
	float re;
	printf("输入金额: ");
	scanf("%d", &m);
	if(m >= 10000) {
		re = m * 0.85;
	}
	if(m < 10000 && m >=5000) {
		re = m * 0.9;
	}
	if(m < 5000 && m >=1000) {
		re = m * 0.95;
	}
	if(m < 1000) {
		re = m * 1;
	}
	printf("实际应付: %.2f\n", re);
} 