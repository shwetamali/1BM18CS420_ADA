#include<stdio.h>
#include<conio.h>
#include <time.h>
void nqueens(int n)
{
	int k,x[20],count=0;
	k=1;
	x[k]=0;
	while(k!=0)
	{
		x[k]++;
		while(place(x,k)!=1 && x[k]<=n)
			x[k]++;
		if(x[k]<=n)
		{
			if(k==n)
			{
				printf("\nSolution is %d\n", ++count);
				printf("Queen\t\tPosition\n");
				for(k=1;k<=n;k++)
					printf("%d\t\t%d\n", k,x[k]);
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
			k--;
	}
}
int place(int x[], int k)
{
	int i;
	for(i=1;i<=k-1;i++)
	{
		if(i+x[i]==k+x[k]||i-x[i]==k-x[k]||x[i]==x[k])
			return 0;
	}
	return 1;
}
void main()
{
	int n;
	clock_t start,end;
	double d;
	clrscr();
	start=clock();
	printf("Enter the number of Queens\n");
	scanf("%d", &n);
	nqueens(n);
	sort(arr,k,n);
	end=clock();
	d=d+(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time complexity:%f",d);
	printf("\n");
	getch();
}
