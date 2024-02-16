#include<stdio.h>
int addTest(int a, int b){
	return a+b;
}
int subTest(int a, int b){
	return a-b;
}
int mulTest(int a, int b){
	return a*b;
}
int divTest(int a, int b){
	if(b == 0){
		return -1;
	}else{
		return a/b;	
	}
}
int remTest(int a, int b){
	if(b == 0){
		return -1;
	}else{
		return a%b;
	}

}
main (){
	int a, b;
	printf("input number a: ");
	scanf("%d", &a);
	printf("input number b: ");
	scanf("%d", &b);
	printf("a+b=%d\n", addTest(a, b));
	printf("a-b=%d\n", subTest(a, b));
	printf("a*=%d\n", mulTest(a, b));
	if(divTest(a, b) == -1){
		printf("除数不能为0\n");
	} else{
		printf("a/b=%d\n", divTest(a, b));
	}
	if(remTest(a, b) == -1){
		printf("除数不能为0\n");
	} else{
		printf("a\%%b=%d\n", remTest(a, b));
	}
} 