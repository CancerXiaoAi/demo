#include<stdio.h>
main(){
	char ch[]="I am fine!";
	int i;
	for(i=0;i<sizeof(ch)/sizeof(char);i++){
		printf("%c", ch[i]);
	}
}