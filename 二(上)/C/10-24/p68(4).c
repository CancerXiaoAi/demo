#include <stdio.h>
#define PI 3.14159

int main() {
    float r, h, cl, cs, cv;
    
    printf("������Բ�뾶r: ");
    scanf("%f", &r);
    printf("������Բ����h: ");
        scanf("%f", &h);
    cl = 2 * PI * r;  // ����Բ�ܳ�
    cs = PI * r * r;  // ����Բ���
    cv = PI * r * r * h;  // ����Բ�����
    
    printf("Բ�ܳ�cl = %.2f\n", cl);
    printf("Բ���cs = %.2f\n", cs);
    printf("Բ�����cv = %.2f\n", cv);
    
    return 0;
}
