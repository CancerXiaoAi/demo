#include<stdio.h>
int passArray(int a[]){
	int i;
	int f=0;
	for(i=0;i<10;i++){
		if(a[i] >= 60){
			f++;
		}
	} 
	return f;
}
main(){
	int a[10] = {60,45,100,90,45,34,49,34,78,90};
	printf("�����ѧ����%d��\n", passArray(a));
}