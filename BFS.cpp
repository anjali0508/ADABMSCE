#include<iostream>
#include<queue>
using namespace std;
void bfs(queue<int> q,int **graph, int *visited,int n);
int main(){
	int n;
	cout<<"Enter no of vertices";
	cin>>n;
	int **graph=new int*[n];
	for(int i=0;i<n;i++){
		graph[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			graph[i][j]=0;
		}
	}
	int m;
	cout<<"Enter no of edges";
	cin>>m;
	int u,v;
	cout<<"Enter two vertices"<<endl;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		graph[u][v]=1;
		graph[v][u]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	int visited[n] = {0};
	queue<int> q;
	int source;
	cout<<"Enter source vertex";
	cin>>source;
	q.push(source);
	visited[source]=1;
	while(!q.empty()){
		int x=q.front();
		cout<<x<<" ";
		q.pop();
		for(int j=0;j<n;j++){
			if(graph[x][j]==1 && visited[j]==0){
				q.push(j);
				visited[j]=1;
			}
		}
	}
}
