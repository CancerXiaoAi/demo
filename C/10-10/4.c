#include <stdio.h>
#include <math.h>
main() {
    double a = 3, b = 4, c = 5; // �����ε����߳�
    double s, area;
    s = (a + b + c) / 2; // ������ܳ�
    area = sqrt(s * (s - a) * (s - b) * (s - c)); // �������
    printf("�����ε����Ϊ��%.2f\n", area);
}
