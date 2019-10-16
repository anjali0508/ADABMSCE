#include<iostream>
using namespace std;
int firstOccurence(int arr[], int low, int high, int x){
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        //cout<<mid<<endl;
        if((arr[mid]==x && arr[mid-1]<x)){
            return mid;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        
    }
    return -1;
}
int lastOccurence(int arr[], int low, int high, int x){
    int mid;
    int n = high;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==x && (arr[mid+1]>x)){
            return mid;
        }
        else if(x<arr[mid]){
             high = mid-1;
            //low=mid+1;
        }
        else{
            low=mid+1;
           
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,2,2,2,3,4};
    int n = 6;
    int key = 2;
    cout<<firstOccurence(arr, 0, n-1, key)<<endl;
    cout<<lastOccurence(arr, 0, n-1, key)<<endl;
}