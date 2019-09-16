#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int adj[10][10],n,v[10];
void input(){
    cout<<"Enter the number of vertices:\n";
    cin>>n;
    for(int i=0;i<n;i++){
        v[i]=0;
    }
    cout<<"Enter graph data in matrix form:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
}
void BFS(int k){
    queue <int> q;
    v[k]=1;
    cout<<k<<",";
    q.push(k);
    while(!q.empty()){
        int f= q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(adj[f][i]==1){
                if(v[i]==0){
                    q.push(i);
                    v[i]=1;
                    cout<<i<<",";
                }
            }
        }
    }
}
int main(){
    clock_t start,end;
	double d;
	start=clock();
    input();
    int s;
    cout<<"Enter the starting vertex:\n";
    cin>>s;
    BFS(s);
    end=clock();
	d=d+(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Time complexity:"<<d;
	return 0;
}
