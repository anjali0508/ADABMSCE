#include<iostream>
using namespace std;
int a[20][20],visited[20],n;

void DFS(int v)
{
	cout<<v<<" ";
	visited[v]=1;
	for(int i=1;i<n;i++)
	{
		if(a[v][i]==1 && visited[i]==0)
			DFS(i);
	}
}
int main()
{
	
	cout<<"\nEnter the no of vertices:";
	cin>>n;
	cout<<"\nEnter the adjacency matrix:";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
		visited[i]=0;
	}
	cout<<"\nConnected components:\n";
	DFS(0);
	for(int i=0;i<n;i++)
	{
		if(visited[i]!=1)
			{
				cout<<"\n";
				DFS(i);
			}
	}
	return 0;
}
