#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[20],n;
    bool flag=false;
    cout<<"Enter size of array:";
    cin>>n;
    cout<<"Enter array elements:";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=floor(n/2);i++)
    {
        if((2*(i))+1<=n)
        {
            if(a[i]>= max(a[2*(i)],a[(2*(i))+1]))
            {
                flag=true;
            }
            else
            {
                flag=false;
                break;
            }
        }
        else
        {
            if(a[i]>=a[2*(i)])
            {
                flag=true;
            }
            else
            {
                flag=false;
                break;
            }
        }
}
if(flag)
{
       cout<<"true";
}
else
{
       cout<<"false";
}
}
