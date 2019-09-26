#include<iostream>
using namespace std;
int arr[50][50];
int n;
void TopologicalSorting(){
	int indegree[n+1];
	for(int i=1;i<=n;i++){
		indegree[i]=0;
		for(int j=1;j<=n;j++){
			indegree[i] = indegree[i] + arr[j][i];
		}
		cout<<indegree[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(indegree[j]==0){
				cout<<j<<" ";
				indegree[j] = -1;
				for(int k=1;k<=n;k++){
					if(arr[j][k]==1)
						indegree[k]--;
				}
			}
		}
	}
}
int main(){
	cout<<"Enter n";
	cin>>n;
	cout<<"Enter adjacency matrix";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	TopologicalSorting();
}
