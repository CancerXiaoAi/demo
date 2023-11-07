//7
//徐锦国 
#include<stdio.h>
main(){
	int grade_s, grade_c;
	float sum;
	printf("请输入大学信息技术和C语言两门课程的成绩\n");
	printf("大学信息技术: ");
	scanf("%d", &grade_s);
	printf("C语言: ");
	scanf("%d", &grade_c);
	sum = grade_s + grade_c;
	printf("两门课程的总分是: %f", sum); 
}