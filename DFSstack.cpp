#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	int edges;
	int graph[5][5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			graph[i][j] = 0;
		}
	}
	cout<<"Enter the number of edges";
	cin>>edges;
	int u, v;
	for(int i=0;i<edges;i++){
		cout<<"Enter the two vertices";
		cin>>u>>v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	stack<int> s;
	vector<bool> visited(5, false);
	int x;
	for(int k=0;k<5;k++){
		if(!visited[k]){
			//cout<<"k:"<<k<<endl;
			s.push(k);
			while(!s.empty()){
				x = s.top();
				s.pop();
				for(int i=0;i<5;i++){
					if(graph[x][i]==1 && visited[i]==false){
						cout<<i<<" ";
						visited[i] = true;
						s.push(i);
					}
				}
			}
			cout<<endl;
		}
	}
	
}

