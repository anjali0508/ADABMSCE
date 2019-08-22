#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cout<<"Enter number of elements";
	cin>>n;
	long int arr[100000];
        for(int i=0;i<n;i++){
                arr[i]=rand()%10000;
        }
	clock_t tStart = clock();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	cout<<"Time taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC;
	cout<<"tHE SORTED ARRAY IS: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Time taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC;
}
