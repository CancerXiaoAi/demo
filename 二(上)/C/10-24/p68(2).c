#include <stdio.h>

int main() {
    float kilometers;

    // 获取用户输入
    printf("请输入公里数：");
    scanf("%f", &kilometers);

    // 公里转米
    float meters = kilometers * 1000;

    printf("%.2f 公里等于 %.2f 米\n", kilometers, meters);

    return 0;
}
