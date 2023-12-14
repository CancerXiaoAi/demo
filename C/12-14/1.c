#include <string.h>
#include <stdio.h>

int main() {
	char string[10];
	printf("请输入一个字符串：");
	scanf("%s", string);
	printf("输入的字符串为：%s\n", string);
	printf("字符串的长度为：%d\n", strlen(string));
}
