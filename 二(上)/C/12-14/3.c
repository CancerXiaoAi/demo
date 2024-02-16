#include <string.h>
#include <stdio.h>

int main() {
	char passwords1[50];
	char passwords2[50];
	printf("请输入密码：");
	scanf("%s", passwords1);
	printf("请再次输入密码：");
	scanf("%s", passwords2);
	if (strcmp(passwords1, passwords2) == 0) {
		printf("密码重设成功！\n");
	} else {
		printf("两次密码不一致！\n");
	}
}
