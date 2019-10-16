#include<iostream>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot, i = low+1, j=high;
    pivot = arr[low];
    while(1){
        while(arr[i]<=pivot && i<=high)
            i++;
        while(arr[j]>pivot && j>=low)
            j--;
        if(i<j){
            int c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
        }
        else{
            arr[low] = arr[j];
            arr[j] = pivot;
            return j;
        }
    }
}
void QuickSort(int arr[], int low, int high, int k){
    int pivot;
    if(low<high){
        pivot = partition(arr, low, high);
        if(pivot==k){
            cout<<"hey";
            cout<<arr[pivot]<<endl;
            return;
        }
        QuickSort(arr, pivot+1, high, k);
        QuickSort(arr, low, pivot-1, k);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter start end and k";
    int start, end, k;
    cin>>start>>end>>k;
    
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    QuickSort(arr, start, end, k);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}