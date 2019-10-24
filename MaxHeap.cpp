#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n+1];
	arr[0] = 0;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	cout<<endl;
	for(int i=1;i<=n/2;i++){
		if(arr[i]<=arr[i*2]){
			if((i*2 + 1)<=n){
				if(arr[i]<=arr[i*2 + 1]){

					cout<<"Not a Max Heap"<<endl;
					return 0;
				}
			}
			cout<<arr[i]<<" ";
			cout<<"Not a Max Heap"<<endl;
			return 0;
		} 
	}
	cout<<"Max Heap"<<endl;
}
