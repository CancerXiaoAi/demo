#include <stdio.h>
 
void oeTest(int num) {
    if (num % 2 == 0) {
        printf("是偶数\n", num);
    } 
	if (num % 2 != 0){
        printf("是奇数\n", num);
    }
}
 
main() {
    int num;
    printf("input an integer: ");
    scanf("%d", &num);
    oeTest(num);
}
