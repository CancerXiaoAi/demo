#include <stdio.h>

int main() {
    float kilometers;

    // ��ȡ�û�����
    printf("�����빫������");
    scanf("%f", &kilometers);

    // ����ת��
    float meters = kilometers * 1000;

    printf("%.2f ������� %.2f ��\n", kilometers, meters);

    return 0;
}
