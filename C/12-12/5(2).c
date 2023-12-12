#include<stdio.h>
main(){
	int a[]={80,56,83,79,91,58,64,85,90,60};
	int n;
	printf("输入你要查找的数据: ");
	scanf("%d", &n);
	
	int i,low=0,high=sizeof(a)/sizeof(int)-1,mid;
	int flag=0;
	while(low<=high){
		mid=(low+high)/2;
		if(n==a[mid]){
			flag=1;
			break;
		}else if(n<a[mid]){
			high=mid-1;
		}else if(n>a[mid]){
			low=mid+1;
		}
	}
	if(flag==1){
		printf("找到了\n");
	}else{	
		printf("没找到!\n");
	}
}