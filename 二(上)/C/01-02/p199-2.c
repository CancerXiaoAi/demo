//3������С�������� 
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
	printf("����ǰ��");
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
	printf("\n�����");
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
	printf("�����������Կո������");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
}