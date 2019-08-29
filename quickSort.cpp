#include<iostream>
#include<algorithm>
using namespace std;
int arr[200];
int partition1(int arr[], int low, int high);
void quicksort1(int arr[], int low, int high){
	int pivot;
	if(low<high){	
		pivot = partition1(arr,low,high);
		quicksort1(arr,low,pivot-1);
		quicksort1(arr,pivot+1,high);
	}
}
int partition1(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for(int k=low;k<high;k++){
		if(arr[k]<pivot){
			i++;
			swap(arr[i],arr[k]);
		}         
	}
	swap(arr[i+1],arr[high]);
	return (i+1);
}
int main(){
	int n;
	cout<<"Enter n";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter element";
		cin>>arr[i];
	}
	quicksort1(arr, 0, n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

}

