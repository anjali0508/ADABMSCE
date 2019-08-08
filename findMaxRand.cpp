#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n;
	cout<<"Enter the number of elements you want";
	std::cin>>n;
	long int arr[1000];
	for(int i=0;i<n;i++){
		arr[i]=rand();
	}
	cout<<"The elements are"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int max = arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	std::cout<<"Max element is "<<max<<endl;
	return 0;
}
