#include<bits/stdc++.h>
using namespace std;
int main(){
	//random_r();
	int n;
	std::cin>>n;
	int arr[20];
	for(int i=0;i<n;i++){
		arr[i]=rand()%100;
	}
	int max = arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	std::cout<<"Max element is "<<max<<endl;
	return 0;
}
