#include<iostream>
#include<time.h>
using namespace std;
void knapsack();
int max(int,int);
int i,j,n,m,p[10],w[10],v[10][10];
int main()
{
    clock_t start,end;
    double d;
    start=clock();
    cout<<"\n Enter the number of items:";
    cin>>n;
    cout<<"\n Enter the weight of each item:\n";
    for(i=1;i<=n;i++)
    {
	cin>>w[i];
    }
    cout<<"\n Enter the value of each item:\n";
    for(i=1;i<=n;i++)
    {
	cin>>p[i];
    }
    cout<<"\n Enter the knapsack's capacity:\t";
    cin>>m;
    knapsack();
    end=clock();
    d=d+(double)(end-start)/CLOCKS_PER_SEC;
    cout<<"\nTime complexity:"<<d;
    return 0;
}
void knapsack()
{
	int x[10];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				v[i][j]=0;
			}
			else if(j-w[i] < 0)
			{
				v[i][j]=v[i-1][j];
			}
			else
			{
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
			}
		}
	}
	cout<<"\n OUTPUT:\n";
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			cout<<"\t"<<v[i][j];
		}
		cout<<"\n\n";
	}
	cout<<"\n The optimal solution is:"<<v[n][m];
	cout<<"\n The vector solution is:";
	for(i=n;i>=1;i--)
	{
		if(v[i][m]!=v[i-1][m])
		{
			x[i]=1;
			m=m-w[i];
		}
		else
		{
			x[i]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<"\t"<<x[i];
	}
}
int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
