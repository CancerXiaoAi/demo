#include<stdio.h>
int main () {
	int m;
	printf("�����·�: ");
	scanf("%d", &m);
	if(m>=3&&m<=5) {
		printf("����\n");
	}
	if(m>=6&&m<=8) {
		printf("�ļ�\n");
	}
	if(m>=9&&m<=11) {
		printf("�＾\n");
	}
	if(m==12||m==1||m==2) {
		printf("����\n");
	}
}