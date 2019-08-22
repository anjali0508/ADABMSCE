#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"\nEnter n";
	cin>>n;
	int low = 1;
	int high = n;
	int mid;
	while(low<=high){
		mid = (low+high)/2;
		if(n==mid*mid){
			cout<<"Square root is "<<mid;
			return 1;
		}
		else if(n<mid*mid){
			high = mid-1;
		}
		else if(n>mid*mid){
			low = mid+1;
		}
	}
	cout<<"Square is not whole number";
	
}

