#include<iostream>
#include<algorithm>
using namespace std;
double MedianOfMergedArray(int X[], int Y[], int x, int y){
    int low = 0;
    int high = x;
    while(low<=high){
        int partitionX = (low+high)/2;
        int partitionY = (x+y+1)/2 - partitionX;

        int maxLeftX = (partitionX==0)?INT_MIN:X[partitionX-1];
        int minRightX = (partitionX==x)?INT_MAX:X[partitionX];

        int maxLeftY = (partitionY==0)?INT_MIN:Y[partitionY-1];
        int minRightY = (partitionY==y)?INT_MAX:Y[partitionY];
        if(maxLeftY<=minRightX && maxLeftX<=minRightY){
            if(x+y%2==0){
                return (double)(max(maxLeftY,maxLeftX)+min(minRightX, minRightY)/2);
            }
            else{
                return (double)(max(maxLeftX,maxLeftY));
            }
        }
        else if(maxLeftX>minRightY){
            high = partitionX-1;
        }
        else{
            low = partitionX+1;
        }

    }
    return 0;
}
int main(){
    int X[] = {1,3,8,9,15,34};
    int sizeX = sizeof(X)/sizeof(int);
    int Y[] = {7,11,18,19,21,25};
    int sizeY = sizeof(Y)/sizeof(int);
    //cout<<sizeX<<" "<<sizeY;
    if(sizeY<sizeX)
        cout<<MedianOfMergedArray(Y, X, sizeY, sizeX);
    else
        cout<<MedianOfMergedArray(X, Y, sizeX, sizeY);
}