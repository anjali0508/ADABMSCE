#include<iostream>
using namespace std;
int x[20];
bool inPlace(int i, int k){
   for(int j=1;j<=k-1;j++){
      if(x[j]==i || abs(j-k)==abs(x[j]-i)){
         return false;
      }
   }
   return true;
}
void NQueen(int k, int n){
   for(int i=1; i<=n;i++){
      if(inPlace(i, k)){
         x[k] = i;
         if(k==n){
            for(int j=1;j<=n;j++){
               cout<<"Queen "<<j<<" is placed at "<<x[j]<<endl;
            }
            cout<<"Next: "<<endl;
         }
         else{
            NQueen(k+1, n);
         }
      }
   }
}
int main(){
   int n;
   cin>>n;
   NQueen(1, n);
}