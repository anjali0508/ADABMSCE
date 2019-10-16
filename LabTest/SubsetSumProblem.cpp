#include<iostream>
#include<algorithm>
using namespace std;
void print(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void sumSubset(int arr[], int tuple[], int sSize, int tSize, int it, int sum, int target){
    if(target==sum){
        print(tuple, tSize);
        if(it+1<sSize && sum+arr[it+1]-arr[it]<=target){
            sumSubset(arr, tuple, sSize, tSize-1, it+1, sum-arr[it], target);
        }
    }
    else{
        if(it+1<sSize && sum+arr[it]<=target){
            for(int i=it;i<sSize;i++){
                tuple[tSize] = arr[i];
                if(sum+arr[i]<=target){
                    sumSubset(arr, tuple, sSize, tSize+1, i+1, sum+arr[i], target);
                }
            }
        }
    }
}
void getSubset(int arr[], int n, int target){
    int tuple[200];
    sort(arr, arr+n);
    sumSubset(arr, tuple, n, 0,0,0,target);
}
int main(){
    int n = 7;
    int arr[] = {8,2,3,7,5,1,13};
    getSubset(arr, n, 15);
}