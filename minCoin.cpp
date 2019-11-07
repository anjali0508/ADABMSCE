#include<iostream>
using namespace std;
void minAmt(int n, int arr[], int amt){
	int DP[amt+1];
	for(int i=0;i<=amt;i++)
		DP[i] = 1000;
	DP[0] = 0;
	for(int i=1;i<=amt;i++){
		for(int j=0;j<n;j++){
			if(arr[j]<=i){
				int subres = DP[i-arr[j]];
				if(subres!=1000 && subres+1<DP[i])
					DP[i] = subres+1;
			}
				
		}
	}
	if(DP[amt]==1000)
		cout<<"Not Possible";
	else
		cout<< DP[amt];
}
int main(){
	int amt;
	cout<<"Enter the amount";
	cin>>amt;
	cout<<"Enter the no of coins";
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the coins  to be used";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	minAmt(n, arr, amt);
	
}
