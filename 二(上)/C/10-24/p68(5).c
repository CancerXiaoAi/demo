#include <stdio.h>

int main() {
    char c;
    printf("请输入一个字符: ");
    scanf("%c", &c);  
    printf("字符 '%c' 的ASCII码是 %d\n", c, c);
    return 0;
}
