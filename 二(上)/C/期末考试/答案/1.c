#include <stdio.h>
 
void oeTest(int num) {
    if (num % 2 == 0) {
        printf("��ż��\n", num);
    } 
	if (num % 2 != 0){
        printf("������\n", num);
    }
}
 
main() {
    int num;
    printf("input an integer: ");
    scanf("%d", &num);
    oeTest(num);
}
