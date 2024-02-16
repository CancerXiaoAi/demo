#include<stdio.h>
main(){
	void v(int scan);
	int scan;
	printf("input a integer: ");
	scanf("%d", &scan);
	v(scan);
}
void v(int scan){
 	if(scan % 2 == 0){
	 	printf("是偶数\n");
	 }
	 if(scan % 2 != 0){
	 	printf("是奇数\n");
	 }
}