#include<stdio.h>
int main () {
	int i,sum;
	for (i=1;i<100;i++) {
		if(i % 3 == 0) {
			sum += i;
		}
	}
			printf("1~100���ڣ��ܱ�3���������ĺ�: %d\n", sum);
}