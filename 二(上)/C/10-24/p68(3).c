#include <stdio.h>

int main() {
    int num1, num2;

    // ��ȡ�û�����
    printf("�������һ������");
    scanf("%d", &num1);
    printf("������ڶ�������");
    scanf("%d", &num2);

    // �����̺�����
    int shang = num1 / num2;
    int yu = num1 % num2;

    printf("�̣�%d, ������%d\n", shang, yu);

    return 0;
}
