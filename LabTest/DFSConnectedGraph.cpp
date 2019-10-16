#include<iostream>
using namespace std;
void DFS(int v, int n, int visited[], int arr[20][20]){
    cout<<v<<" ";
    visited[v] = 1;
    for(int i=0;i<n;i++){
        if(arr[v][i]==1 && visited[i]==0)
            DFS(i,n,visited, arr);
    }
}
int main(){
    int n;
    cin>>n;
    int visited[20];
    int arr[20][20];
    cout<<"Enter adjacency matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
        visited[i] = 0;
    }
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            cout<<"\n";
            DFS(i, n, visited, arr);
        }
    }
    return 0;
}