//3个数从小到大排序 
#include<stdio.h>
#define N 3
void inputData(int a[N]);
void printData(int a[N]); 
void sortData(int a[]);
main()
{
	int a[N];
	inputData(a);
	sortData(a);
} 
void sortData(int a[N])
{
	printf("排序前：");
	printData(a);
	int i,j,temp;
	for (i=0;i<N;i++)
	{
		for(j=0;j<N-1-i;j++)
		{
			if(a[j+1]<a[j])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\n排序后：");
	printData(a);
}
void printData(int a[N])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
}
void inputData(int a[N])
{
	int i;
	printf("请输入数据以空格隔开：");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
}