#include<iostream>
#include<algorithm>
int comp = 0;
using namespace std;
int main(){
	int n;
	cout<<"Enter the size of an array :\n";
	cin>>n;
	int arr[20];
	cout<<"Enter elements of an array:\n";
	for(int i=0;i<n;i++)	
		cin>>arr[i];
	int max;
	for(int i=0;i<n;i++){
		max = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]>arr[max]){
				comp++;
				swap(arr[j],arr[max]);
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"The number of comparisions are: "<<comp;
	
}	
