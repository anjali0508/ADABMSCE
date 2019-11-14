#include<iostream>
#define V 5
using namespace std;
int main(){
    int graph[V][V] = {{9999,5,9999,9999,9999},{9999,9999,3,2,9999},{4,9999,9999,9999,9999},{9999,2,9999,9999,6},{5,9999,9999,9999,9999}};
    int src = 0;
    int dist[V];
    int vis[V];
    for(int i=0;i<V;i++){
        dist[i] = graph[src][i];
        vis[i] = 0;
    }
    int count = 1;
    dist[0] = 0;
    cout<<endl;
    while(count!=V){
        int min = 9999;
        int u;
        for(int j=0;j<V;j++){
            if(dist[j]<min && vis[j]!=1){
                min = dist[j];
                u = j;  
            }
        }
        vis[u] = 1;
        count++;
        for(int j=0;j<V;j++){
            if(min+graph[u][j]<dist[j])
                dist[j] = min+graph[u][j];
        }
    }
    cout<<"Shortest ditance is: "<<endl;
    for(int j=0;j<V;j++)
        cout<<src<<" "<<j<<" "<<dist[j]<<endl;
}
