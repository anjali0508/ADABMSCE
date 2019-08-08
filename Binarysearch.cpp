#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)
		arr[i] = rand()%1000;
	cout<<"Enter the element to search";
	int k;
	cin>>k;
	sort(arr,arr+n);
	int low = 0;
	int high = n-1;
	int mid;	
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==k){
			cout<<"Element found"<<endl;
			return 0;
		}
		else if(arr[mid]>k){
			high = mid-1;
		}
		else if(arr[mid]<k){
			low = mid+1;
		}
	}
	cout<<"Element not found";
}
