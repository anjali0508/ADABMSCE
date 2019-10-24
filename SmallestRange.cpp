#include<iostream>
#include<vector> 
using namespace std;
int main(){
	cout<<"Enter no of lists";
	int k;
	cin>>k;
	cout<<"Enter number of elements in each lists";
	int n;
	cin>>n;
	int arr[k][n];
	for(int j=0;j<k;j++){
		for(int i=0;i<n;i++){
			cin>>arr[j][i];
		}
	}
	for(int j=0;j<k;j++){
		for(int i=0;i<n;i++){
			cout<<arr[j][i]<<" ";
		}
		cout<<endl;
	}
	vector<int> v(k,0);
	int range=1000;
	int start, end;
	int flag = 0;
	while(1){
		int minele=1000, maxele=-1000;
		int minIndex, maxIndex;
		for(int i=0;i<k;i++){
			if(arr[i][v[i]]<minele){
				minele = arr[i][v[i]];
				minIndex = i;
				cout<<"minIndex: "<<minIndex<<" "<<minele<<endl;
			}
			if(arr[i][v[i]]>maxele){
				maxele = arr[i][v[i]];
				maxIndex = i;
				cout<<"maxIndex: "<<maxIndex<<" "<<maxele<<endl;
			}
		}
		if(maxIndex-minIndex<range){
			range = maxIndex-minIndex;
			start = minele;
			end = maxele;
		}
		v[minIndex]++;
		if(v[minIndex]==n){
			break;
		}
	}
	cout<<start<<" "<<end;
}
