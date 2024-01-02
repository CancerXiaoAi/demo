#include<stdio.h>
main(){
	void s(int scan);
	int scan;
	printf("input a secend: ");
	scanf("%d", &scan);
	s(scan);
}
void s(int scan){
    int h,m,s;
    h = scan/3600;
    m = scan%3600/60;
    s = scan%60;
    printf("%d:%d:%d", h, m, s);
}