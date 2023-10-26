#include <stdio.h>

int main() {
    int num1, num2;

    // 获取用户输入
    printf("请输入第一个数：");
    scanf("%d", &num1);
    printf("请输入第二个数：");
    scanf("%d", &num2);

    // 计算商和余数
    int shang = num1 / num2;
    int yu = num1 % num2;

    printf("商：%d, 余数：%d\n", shang, yu);

    return 0;
}
