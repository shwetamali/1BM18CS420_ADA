#include<iostream>
#include<time.h>
using namespace std;
class components
{
    int adjacent[20][20],visited[20],a,n,i,j;
	public:void input()
	{
        cout<<"Enter number of components:";
        cin>>n;
        for (i=0;i<n;i++)
		{
            visited[i]=0;
        }
		cout<<"Enter adjacent matrix:";
        for(i=0;i<n;i++)
		{
            for(j=0;j<n;j++)
			{
                cin>>adjacent[i][j];
            }
		}
	}
		void dfs(int a)
		{
			cout<<a+1<<",";
			visited[a]=1;
			for(i=0;i<n;i++)
			{
				if(adjacent[a][i]==1 && visited[i]==0)
				{
					dfs(i);
				}
			}
		}
		void com()
		{
			for(j=0;j<n;j++)
			{
				if(visited[j]==0)
				{
					dfs(j);
				}
			}
		}
	};
int main()
{
	clock_t start,end;
	double d;
	start=clock();
	components s;
	s.input();
	s.com();
	end=clock();
	d=d+(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Time complexity:"<<d;
	return 0;
}
		
