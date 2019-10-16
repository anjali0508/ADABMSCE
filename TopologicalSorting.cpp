#include<iostream>
using namespace std;
int arr[20][20];
int indegree[20];
void TopologicalSorting(int n){
    for(int i=0;i<n;i++){
        indegree[i] = 0;
        for(int j=0;j<n;j++){
            indegree[i] += arr[j][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(indegree[j]==0){
                cout<<j<<" ";
                indegree[j]=-1;
                for(int k=0;k<n;k++){
                    if(arr[j][k]==1)
                        indegree[k]--;
                }
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    cout<<"Enter adjacency matrix";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    TopologicalSorting(n);
}