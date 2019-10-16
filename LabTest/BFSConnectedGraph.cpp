#include<iostream>
#include<queue>
using namespace std;
void BFS(int v, int visited[], int arr[20][20], int n){
    queue<int> q;
    q.push(v);
    visited[v]= 1;
    while(!q.empty()){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        visited[x] = 1;
        for(int i=0;i<n;i++){
            if(visited[i]==0 && arr[x][i]==1){
                q.push(i);
            }
        }
        
    }
}
int main(){
    int n;
    cin>>n;
    int arr[20][20];
    int visited[20];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
        visited[i] = 0;
    }
    for(int i=0;i<n;i++){
        cout<<endl;
        if(visited[i]==0)
            BFS(i, visited, arr, n);
    }
}