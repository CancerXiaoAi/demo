#include <stdio.h>
int main () {
	char c;
	printf("输入一个字符: ");
	scanf("%c", &c);
	if(c >= 97 && c <= 122 || c >= 65 && c <= 90) {
		printf("输入的是字母\n");
	}
	if (c >= 48 && c <= 57) {
		printf("输入的是数字\n");
	}
	if (c == ' ') {
		printf("输入的是空格\n");
	}
}