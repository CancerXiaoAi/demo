#include <stdio.h>
 main() {
    char passwords1[50], passwords2[50];
    printf("��������: ");
    scanf("%s", passwords1);
    printf("�ٴ�����: ");
    scanf("%s", passwords2);
    if (strcmp(passwords1, passwords2) == 0) {
        printf("��������ɹ�\n");
    } else {
        printf("�������벻һ��\n");
    }
}