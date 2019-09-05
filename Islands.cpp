#include<iostream>
#define COL 5
#define ROW 3
using namespace std;
int isSafe(int M[][COL],int row,int col,bool visited[][COL]);
void DFS(int M[][COL], int row, int col, bool visited[][COL]);
int countIslands(int M[][COL]){
	bool visited[ROW][COL];
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			visited[i][j] = false;
		}
	}
	int count = 0;
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			if(M[i][j] && !visited[i][j]){
				DFS(M,i,j,visited);
				++count;
			}
		}
	}
	return count;
}
void DFS(int M[][COL], int row, int col, bool visited[][COL]){
	static int rowNbr[] = {-1,-1,-1,0,0,1,1,1};
	static int colNbr[] = {-1,0,1,-1,1,-1,0,1};
	visited[row][col] = true;
	for(int k=0;k<8;k++){
		if(isSafe(M,row+rowNbr[k],col+colNbr[k],visited)){
			DFS(M,row+rowNbr[k],col+colNbr[k],visited);
		}
	}
}
int isSafe(int M[][COL],int row,int col,bool visited[][COL]){
	return (row>=0) && (row<ROW) && (col>=0) && (col<COL) && (M[row][col] && !visited[row][col]);
}
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
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<countIslands(graph);
}
