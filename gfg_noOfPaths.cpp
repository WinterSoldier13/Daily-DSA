#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> makeBoard(int m, int n)
{
    vector<int> temp(n,0);
    vector<vector<int>> board(m, temp);

    return board;
}
void printBoard(vector<vector<int>> &board)
{
    for(auto x: board)
    {
        for(int c:x)
        cout<<c<<" ";
        cout<<endl;
    }
}



void recurse(vector<vector<int>> &board, int i, int j, vector<int> &path)
{
    if(i == board.size()-1 and j==board[0].size()-1)
    {
        path.push_back(1);
        return;
    }
    if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j] == 1)
    {
        return;
    }

    board[i][j] = 1;
    // printBoard(board);
    recurse(board, i+1,j,path);
    recurse(board, i,j+1, path);
    board[i][j] = 0;

}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
       int m, n;
       cin>>m>>n;

       vector<vector<int>> board = makeBoard(m,n);
       vector<int> path;
       recurse(board, 0,0, path);
    //   printBoard(board);

       cout<<path.size()<<endl;


    }
}