#include<stdio.h>
main(){
	char ch[]={'I',' ','a','m',' ','f','i','n','e','!'};
	int i;
	for(i=0;i<sizeof(ch)/sizeof(char);i++){
		printf("%c", ch[i]);
	}
}