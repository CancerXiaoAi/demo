#include<stdio.h>
int main () {
	int m;
	printf("ÊäÈëÔÂ·Ý: ");
	scanf("%d", &m);
	if(m>=3&&m<=5) {
		printf("´º¼¾\n");
	}
	if(m>=6&&m<=8) {
		printf("ÏÄ¼¾\n");
	}
	if(m>=9&&m<=11) {
		printf("Çï¼¾\n");
	}
	if(m==12||m==1||m==2) {
		printf("¶¬¼¾\n");
	}
}