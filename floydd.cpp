#include<iostream>
#define V 5
using namespace std;
int main(){
    int graph[V][V] = {{0,5,9999,9999,9999},{9999,0,3,2,9999},{4,9999,0,9999,9999},{9999,2,9999,0,6},{5,9999,9999,9999,0}};
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
