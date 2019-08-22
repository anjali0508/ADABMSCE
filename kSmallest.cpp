#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cout<<"Enter n";
	cin>>n;
	int arr[20];
	cout<<"Enter elements";
	for(int i=0;i<n;i++)	
		cin>>arr[i];
	cout<<"Enter k";
	int k;
	cin>>k;
	if(k<=0){
		cout<<"k cannot be less than or equal to zero";
	}
	int min;
	for(int i=0;i<k;i++){
		min = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				swap(arr[j],arr[min]);
			}
		}
	}
	cout<<arr[k-1];
}	
