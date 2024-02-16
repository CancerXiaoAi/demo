#include <string.h>
#include <stdio.h>

int main() {
	char str1[10];
	char str2[10];
	char result[20];
	printf("请输入第一个字符串：");
	scanf("%s", str1);
	printf("请输入第二个字符串：");
	scanf("%s", str2);
	printf("第一个字符串为：%s\n", str1);
	printf("第二个字符串为：%s\n", str2);
	strcpy(result, str1);
	strcat(result, str2);
	printf("连接后的字符串为：%s\n", result);
}
