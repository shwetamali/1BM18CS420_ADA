#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sort(int a[],int k,int n)
{
	for(int i=0;i<k-2;i++)
    {
		int min=i;
		for(int j=i+1;j<n-1;j++)
		{
			if (a[j]<a[min])
				{
					min=j;
				}
		}
		int temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	return a[k-1];
}
int main()
{
	int n,arr[19],k;
	clock_t start,end;
	double d;
	start=clock();
	printf("Enter the size of an array elements:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the key:\n");
	scanf("%d",&k);
	printf("kth smallest number:%d\n",sort(arr,k,n));
	end=clock();
	d=d+(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time complexity:%f",d);
	printf("\n");
	return 0;
}

