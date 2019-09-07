#include<iostream>
#include<time.h>
#define ROW 50
#define COL 50
using namespace std;
int p[ROW][COL],s1,s2;
bool visited[ROW][COL];
void input()
{
		int i,j;
        cout<<"Enter no of rows:";
        cin>>s1;
        cout<<"Enter no of columns:";
        cin>>s2;
        for(i=0;i<s1;i++)
		{
            for(j=0;j<s2;j++)
			{
            visited[i][j]=false;
			}
        }
        cout<<"Enter matrix:";
        for(i=0;i<s1;i++)
		{
            for(j=0;j<s2;j++)
			{
                cin>>p[i][j];
            }
		}
}
int isSafe(int p[][COL],int row,int col,bool visited[][COL])
{
	return ((row>=0)&&(row<s1)&&(col>=0)&&(col<s2)&&(p[row][col]&& !visited[row][col]));
}
void DFS(int p[][COL],int row,int col,bool visited[][COL])
{
	static int rowNbr[]={-1,-1,-1,0,0,1,1,1};
	static int colNbr[]={-1,0,1,-1,1,-1,0,1};
	visited[row][col]=true;
	for(int k=0;k<8;k++)
	{
		if(isSafe(p,row+rowNbr[k],col+colNbr[k],visited))
		{
			DFS(p,row+rowNbr[k],col+colNbr[k],visited);
		}
	}
}
int countIslands(int p[][COL])
{
		int count=0;
		for(int i=0;i<s1;++i)
		{
		for(int j=0;j<s2;++j)
		{
			if(p[i][j] && !visited[i][j])
			{
				DFS(p,i,j,visited);
				++count;
			}
		}
	}
	return count;
}
int main()
{
	clock_t start,end;
	double d;
	start=clock();
	input();
	int n=countIslands(p);
	cout<<" Island:"<<n;
	end=clock();
	d=d+(double)(end-start)/CLOCKS_PER_SEC;
	cout<<endl<<"Time Complexity:"<<d;
	return 0;
}
