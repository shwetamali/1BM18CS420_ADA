#include<iostream>
#include<conio.h>
using namespace std;
int a[10][10],n;
void floyds();
int min(int,int);
int main()
{
 int i,j;
 cout<<"\nEnter the no. of vertices:\t";
 cin>>n;
 cout<<"\nEnter the cost matrix:\n";
 for(i=1;i<=n;i++)
 {
    for(j=1;j<=n;j++)
    {
       cin>>a[i][j];
    }
 }
 floyds();
 getch();
}

void floyds()
{
 int i,j,k;
 for(k=1;k<=n;k++)
 {
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
   }
  }
 }
 cout<<"\nall pair shortest path matrix is:\n";
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
    cout<<a[i][j]<<"\t";
  }
  cout<<"\n\n";
 }
}

int min(int x,int y)
{
 if(x<y)
 {
  return x;
 }
 else
 {
  return y;
 }
}
