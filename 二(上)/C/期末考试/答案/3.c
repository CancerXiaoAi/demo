#include <stdio.h>
 main() {
    char passwords1[50], passwords2[50];
    printf("输入密码: ");
    scanf("%s", passwords1);
    printf("再次输入: ");
    scanf("%s", passwords2);
    if (strcmp(passwords1, passwords2) == 0) {
        printf("密码重设成功\n");
    } else {
        printf("两次密码不一样\n");
    }
}