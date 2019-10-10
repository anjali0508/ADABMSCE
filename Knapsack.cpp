#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cout<<"Enter no of items";
	cin>>n;
	int w;
	cout<<"Enter capacity";
	cin>>w;
	int val[n], wt[n];
	cout<<"Enter "<<n<<" values";
	for(int i=0;i<n;i++)
		cin>>val[i];
	for(int i=0;i<n;i++)
		cin>>wt[i];
	int table[n+1][w+1] = {0};
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++)
			table[i][j] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			 if(j<wt[i-1]){
					table[i][j] = table[i-1][j];
			}
			else{
					table[i][j] = max(table[i-1][j], val[i-1]+table[i-1][j-wt[i-1]]);
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<table[n][w];
}
