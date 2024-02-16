#include <string.h>
#include <stdio.h>
int main() {
	char str1[50];
	char str2[50];
	char temp[50];
	printf("请输入第一个字符串: ");
	scanf("%s", str1);
	printf("请输入第二个字符串：");
	scanf("%s", str2);
	printf("交换前的第一个字符串为：%s\n", str1);
	printf("交换前的第二个字符串为：%s\n", str2);
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	printf("交换后的第一个字符串为：%s\n", str1);
	printf("交换后的第二个字符串为：%s\n", str2);
}
