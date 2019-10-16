#include<iostream>
using namespace std;
int findElement(int arr[], int low, int high, int key){
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        cout<<"mid: "<<mid<<endl;
        if(key==arr[mid]){
            return mid;
        }
        if(arr[mid]<arr[high]){
            if(key<=arr[high] && key>arr[mid])
                low=mid+1;
            else
            {
                high = mid-1;
            }
            
        }
        else{
            if(key>=arr[low] && key<arr[mid]){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return -1;
}
int main(){
    int n = 7;
    int arr[] = {89,101,151,6,9,11,67};
    cout<<findElement(arr, 0, n-1, 151);
}