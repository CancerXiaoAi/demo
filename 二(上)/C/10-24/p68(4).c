#include <stdio.h>
#define PI 3.14159

int main() {
    float r, h, cl, cs, cv;
    
    printf("请输入圆半径r: ");
    scanf("%f", &r);
    printf("请输入圆柱高h: ");
        scanf("%f", &h);
    cl = 2 * PI * r;  // 计算圆周长
    cs = PI * r * r;  // 计算圆面积
    cv = PI * r * r * h;  // 计算圆柱体积
    
    printf("圆周长cl = %.2f\n", cl);
    printf("圆面积cs = %.2f\n", cs);
    printf("圆柱体积cv = %.2f\n", cv);
    
    return 0;
}
