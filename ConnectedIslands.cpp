#include<iostream>
#define ROW 3
#define COL 5
using namespace std;
bool isSafe(int M[][COL], int visited[][COL], int row, int col){
    return row>=0 && col>=0 && row<ROW && col<COL && M[row][col] && !visited[row][col];
}
void DFS(int M[][COL], int visited[][COL], int row, int col){
    visited[row][col] = 1;
    static int rowNbr[8] = {-1,-1,-1,0,0,1,1,1};
    static int colNbr[8] = {-1,0,1,-1,1,-1,0,1};
    for(int k=0;k<8;k++){
        if(isSafe(M, visited, row+rowNbr[k], col+colNbr[k])){
            DFS(M, visited, row+rowNbr[k], col+colNbr[k]);
        }
    }
}
int countIslands(int M[][COL]){
    int visited[ROW][COL];
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++)
            visited[i][j] = 0;
    }
    int count = 0;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(M[i][j] && visited[i][j]==0){
                DFS(M, visited, i, j);
                count++;
            }
        }
    }
    return count;
}
int main(){
    cout<<"Enter adjacency matrix"<<endl;
    int M[ROW][COL];
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++)
            cin>>M[i][j];
    }
    cout<<countIslands(M);
}