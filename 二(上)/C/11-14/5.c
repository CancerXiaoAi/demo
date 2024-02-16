#include <stdio.h>
int main () {
	char c;
	printf("输入一个字母: ");
	scanf("%c", &c);
	if(c >= 'A' && c <= 'Z'){
		printf("输出为: %c\n", c + 32);
	}else{
		printf("输出为: %c\n", c);
	}
}