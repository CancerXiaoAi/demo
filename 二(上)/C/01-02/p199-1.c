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
	 	printf("��ż��\n");
	 }
	 if(scan % 2 != 0){
	 	printf("������\n");
	 }
}