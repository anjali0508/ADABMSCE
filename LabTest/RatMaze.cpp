
#include<bits/stdc++.h>
using namespace std;
#define N 100
int maze[N][N];
void mazeSolver(int startR, int startC, int reqP[N][N], int n ){
    if(startR == n-1 && startC == n-1)
    {
        reqP[n-1][n-1] = 1;
        cout<<"**"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<reqP[i][j]<<" ";
            cout<<endl;
        }
        return ;
    }
    if(startR == n)
        return;
    if(startC == n)
        return;
    if(maze[startR][startC] == 1 && reqP[startR][startC] == 0){
        reqP[startR][startC] = 1;
        mazeSolver(startR + 1, startC, reqP, n);
        mazeSolver(startR, startC + 1, reqP, n);
        reqP[startR][startC] = 0;
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter the maze: \n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>maze[i][j];
    int reqP[N][N];
    memset(reqP,0, sizeof(reqP));
    mazeSolver(0, 0, reqP, n);
    return 0;
}
