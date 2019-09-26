#include<iostream>
using namespace std;
int x[50];
bool inplace(int k, int i){
	for(int j=1;j<=k-1;j++){
		if((x[j]==i) or (abs(x[j]-i)==abs(j-k))){
			return false;
		}
	}
	return true;
}
void NQueens(int k, int n){
	for(int i=1;i<=n;i++){
		if(inplace(k,i)){
			x[k]=i;
			if(k==n){
				for(int j=1;j<=n;j++){
					cout<<j<<" queen present at "<<x[j]<<endl;
				}
				cout<<"Next: "<<endl;
			}
			else{
				NQueens(k+1, n);
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	NQueens(1,n);
}

