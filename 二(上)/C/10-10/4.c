#include <stdio.h>
#include <math.h>
main() {
    double a = 3, b = 4, c = 5; // 三角形的三边长
    double s, area;
    s = (a + b + c) / 2; // 计算半周长
    area = sqrt(s * (s - a) * (s - b) * (s - c)); // 计算面积
    printf("三角形的面积为：%.2f\n", area);
}
