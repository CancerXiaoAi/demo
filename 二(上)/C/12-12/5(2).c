#include<stdio.h>
main(){
	int a[]={80,56,83,79,91,58,64,85,90,60};
	int n;
	printf("������Ҫ���ҵ�����: ");
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
		printf("�ҵ���\n");
	}else{	
		printf("û�ҵ�!\n");
	}
}