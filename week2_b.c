#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int a[],int k,int n)
{
	for(int i=0;i<=k-1;i++)
	{
		for(int j=0;j<=n-2-i;j++)
		{
			if (a[j+1]<a[j])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		} 
		printf("%d\n",a[n-i-1]);
	}
}
int main()
{
	int n,arr[30],k;
	clock_t start,end;
	double d;
	start=clock();
	printf("Enter array size:\n");
	scanf("%d",&n);
	printf("Enter the array element:\n");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the key element to search:\n");
	scanf("%d",&k);
	sort(arr,k,n);
	end=clock();
	d=d+(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time complexity:%f",d);
	printf("\n");
	return 0;
}
