#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int K;

void makeBoard()
{
    vector<int> t(8,-1);
    vector<vector<int>> temp(8,t);
    board = temp;
}
void printBoard()
{
    for (auto x: board)
    {
        for (auto c:x)
        cout<<c<<" ";
        cout<<endl;
    }
}

void fillMatrix(int i, int j)
{
    if(i<0 or j<0 or i>=8 or j>=8 or board[i][j]!=-1 or K==0)
    return;

    K--;
    board[i][j] = 1;

    fillMatrix(i-1,j);
    fillMatrix(i-1,j+1);
    fillMatrix(i,j+1);
    fillMatrix(i+1,j+1);
    fillMatrix(i+1,j);
    fillMatrix(i+1,j-1);
    fillMatrix(i,j-1);
    fillMatrix(i-1,j-1);

}

void placeObstacles(int i, int j)
{
    if(i<0 or j<0 or i>=8 or j>=8 or board[i][j]!=1 or K==0)
    return;

    K--;
    board[i][j] = 2;

    if(i-1>=0)
    if(board[i-1][j] == -1)
    board[i-1][j] = 0;
    

    if(i-1>=0 and j+1<8)
    if(board[i-1][j+1] == -1)
    board[i-1][j+1] = 0;

    if(j+1<8)
    if(board[i][j+1] == -1)
    board[i][j+1] = 0;

    if(i+1<8 and j+1<8)
    if(board[i+1][j+1] == -1)
    board[i+1][j+1] = 0;

    if(i+1<8)
    if(board[i+1][j] == -1)
    board[i+1][j] = 0;

    if(i+1<8 and j-1>=0)
    if(board[i+1][j-1] == -1)
    board[i+1][j-1] = 0;

    if(j-1>=0)
    if(board[i][j-1] == -1)
    board[i][j-1] = 0;

    if(i-1>=0 and j-1>=0)
    if(board[i-1][j-1] == -1)
    board[i-1][j-1] = 0;

    placeObstacles(i-1,j);
    placeObstacles(i-1,j+1);
    placeObstacles(i,j+1);
    placeObstacles(i+1,j+1);
    placeObstacles(i+1,j);
    placeObstacles(i+1,j-1);
    placeObstacles(i,j-1);
    placeObstacles(i-1,j-1);

    board[i][j] = 1;

}

vector<vector<char>> cvtBoard()
{
    vector<char> t(8,'.');
    vector<vector<char>> arr(8,t);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[i][j] == 0)
            arr[i][j]='X';
        }
    }
    arr[0][0] = 'O';

    return arr;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        K = k;

        makeBoard();
        // printBoard();

        fillMatrix(0,0);
        K = k;
        printBoard();
        placeObstacles(0,0);

        vector<vector<char>> arr = cvtBoard();

        for(auto x: arr)
        {
            for(auto c:x)
            cout<<c;
            cout<<endl;
        }




    }
}