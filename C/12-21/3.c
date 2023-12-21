#include<stdio.h>
int searchArray(int a[]){
	int i;
	int f=0;
	for(i=0;i<10;i++){
		if(a[i] == 88){
			f=1;
		}
	} 
	return f;
}
main(){
	int a[10] = {60,45,100,90,45,34,49,34,78,90};
	if(searchArray(a) == 0){
		printf("没有88分的学生\n");
	} 
	if(searchArray(a) == 1){
		printf("有88分的学生\n");
	} 
}