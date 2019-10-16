#include<bits/stdc++.h>
#define R 4
#define C 4
using namespace std;
int BFS(char M[][C], int startRow, int startCol, bool visited[][C], int level[][C])
{
    queue<pair<int,int>> q;
    q.push(make_pair(startRow, startCol));
    visited[startRow][startCol] = 1;
    int x[] = {0, -1, 1, 0};
    int y[] = {-1, 0, 0, 1};
    while(!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int row = front.first + x[i];
            int col = front.second + y[i];
            if((row >= 0) && (row < R) && (col >= 0) && (col < C) && !visited[row][col])
                {
                    q.push(make_pair(row, col));
                    visited[row][col] = 1;
                    level[row][col] = level[front.first][front.second] + 1;
                    if(M[row][col] == 'd')
                        return level[row][col];
                }
        }
    }
    return -1;
}

int pathDist(char M[][C])
{
    int level[R][C], startR, startC;
    bool visited[R][C];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
        {
                visited[i][j] = 0;
                level[i][j] = 0;
        }
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            {
                if(M[i][j] == '0')
                    visited[i][j] = 1;
                if(M[i][j] == 's')
                    {
                        startR = i;
                        startC = j; 
                    }
            }
    return BFS(M, startR, startC, visited, level);
}

int main()
{   char M[R][C];
    cout<<"Enter the maze: \n";
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin>>M[i][j];
    cout<<pathDist(M)<<endl;
    return 0;
}