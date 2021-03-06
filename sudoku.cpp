#include<iostream>
#define UNASSIGNED 0
#define N 9
using namespace std;
int grid[N][N];
bool FindUnassignedLocation(int grid[N][N],int &row,int &col){
	for(row=0;row<N;row++){
		for(col=0;col<N;col++){
			if(grid[row][col]==UNASSIGNED)
				return true;
		}
	}
	return false;
}
bool usedInRow(int grid[N][N], int row,int num){
	for(int col=0;col<N;col++){
		if(grid[row][col]==num)
			return true;
	}
	return false;
}
bool usedInCol(int grid[N][N],int col,int num){
	for(int row=0;row<N;row++){
		if(grid[row][col]==num)
			return true;
	}
	return false;
}
bool usedInBox(int grid[N][N], int rowCheck, int colCheck, int num){
	for(int row=0;row<3;row++){
		for(int col=0;col<3;col++){
			if(grid[row+rowCheck][col+colCheck]==num)
				return true;
			
		}
	}
	return false;
}
bool isSafe(int grid[N][N], int row, int col, int num){
	return !usedInRow(grid,row,num) && !usedInCol(grid,col,num) && !usedInBox(grid,row-row%3,col-col%3,num);
}
bool solveSudoku(int grid[N][N]){
	int row,col;
	if(!FindUnassignedLocation(grid,row,col))
		return true;
	for(int num=1;num<=9;num++){
		if(isSafe(grid,row,col,num)){
			grid[row][col]=num;
			if(solveSudoku(grid))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}
void printSudoku(int grid[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	 int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},

						{5, 2, 0, 0, 0, 0, 0, 0, 0},

						{0, 8, 7, 0, 0, 0, 0, 3, 1},

						{0, 0, 3, 0, 1, 0, 0, 8, 0},

						{9, 0, 0, 8, 6, 3, 0, 0, 5},

						{0, 5, 0, 0, 9, 0, 6, 0, 0},

						{1, 3, 0, 0, 0, 0, 2, 5, 0},

						{0, 0, 0, 0, 0, 0, 0, 7, 4},

						{0, 0, 5, 2, 0, 6, 3, 0, 0}};
	  if(solveSudoku(grid)){
	  	printSudoku(grid);
	  }
	 else{
	 	cout<<"Sudoku cant be solved";
	 }
}
