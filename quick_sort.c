#include <stdio.h>
#include <time.h>
void quick_sort(int[],int,int);
int partition(int[],int,int);
int main()
{
    int a[50],n,i;
	clock_t start,end;
	double d;
	start=clock();
    printf("Enter array size:\n");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    printf("Array after sorting:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
		end=clock();
	d=d+(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time complexity:%f",d);
	printf("\n");
    return 0;
}

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
		{
            i++;

        }while(a[i]<v&&i<=u);

        do
		{
            j--;
        }while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}
