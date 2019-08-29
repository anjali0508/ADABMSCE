#include<iostream>
using namespace std;
int arr[20];
int comp = 0;
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low,int high){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1, high);
		merge(arr,low,mid,high);
	}
}
void merge(int arr[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int left[n1], right[n2];
	for(int i=0;i<n1;i++){
		left[i] = arr[l+i];
	}
	for(int i=0;i<n2;i++){
		right[i] = arr[m+1+i];
	}
	int i = 0;
	int j = 0;
	int k = l;
	//int temp1[20];
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			comp++;
			arr[k++] = left[i++];
		}
		if(left[i]>right[j]){
			comp++;
			arr[k++] = right[j++];
		}
	}
	while(i<n1){
		arr[k++] = left[i++];
	}
	while(j<n2){
		arr[k++] = right[j++];
	}
}
int main(){
	int n;
	cout<<"Enter n";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter element";
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"The number of comparisions are: "<<comp;

}

