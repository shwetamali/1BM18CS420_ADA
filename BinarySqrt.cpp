#include <iostream>
#include <time.h>
using namespace std;
int Squareroot(int x)  
{     
    if (x == 0 || x == 1)  
       return x; 

    int start = 1,end = x,ans;    
    while (start<=end)  
    {         
        int mid=(start + end)/2; 
        if(mid*mid==x) 
            return mid; 
  
        if(mid*mid<x)  
        { 
            start=mid+1; 
            ans=mid; 
        }  
        else 
            end=mid-1;         
    } 
    return ans; 
} 
int main()  
{    
	clock_t start,end;
	double d;
    int x;
	start=clock();
	cout<<"Enter number to find square root:";
	cin>>x;
    cout <<Squareroot(x)<<endl; 
	end=clock();
	d+=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Time complexity:"<<d;
	cout<<"\n";
	return 0;
} 
