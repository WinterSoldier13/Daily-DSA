#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;
#define UNASSIGNED -1  
#define N 9

// SUDOKU

vector<vector<int>> board;


void constructBoard(vector<string> b)
{
     
     for (string row: b)
     {
          vector<int> temp;
          for(char ele: row)
          {
               if(ele=='.')
               {
                    temp.push_back(-1);

               }
               else
               {
                    temp.push_back(ele-'0');
               }

          }
          board.push_back(temp);
          
     }
}

void printBoard()
{
     for(auto x: board)
     {
          for(auto c:x)
          {
               cout<<c<<" ";
          }
          cout<<endl;
     }
}




bool isSafe(int num, int row, int col)
{
     for(int i=0;i<9;i++)
     {
          if(board[row][i]==num)
          {
               return false;
          }
     }

     for(int i=0;i<9;i++)
     {
          if(board[i][col]==num)
          {
               return false;
          }
     }

     int x = row-row%3;
     int y = col-col%3;

     for(int i=0;i<3;i++)
     {
          for(int j=0;j<3;j++)
          {
               if(board[x+i][y+j]==num)
               {
                    return false;
               }
          }
     }
     return true;     


}


pair<int,int> findZ()
{
     for(int i=0;i<9;i++)
     {
          for(int j=0;j<9;j++)
          {
               if(board[i][j]==-1)
               {
                    return make_pair(i,j);
               }
          }
     }
     return make_pair(-1,-1);
}
bool sudoku()
{
     if(findZ().first==-1)
     {
          return true;
     }
     int row = findZ().first;
     int col = findZ().second;
     for(int i=1;i<=9;i++)
     {
          if(isSafe(i,row,col))
          {
               // cout<<row<<" "<<col<<endl;
               board[row][col] = i;
               if(sudoku())
               {
                   return true;
               }
               board[row][col] =-1;
          }
          
     }
     return false;
}
int main()
{
    vector<string> arr{"53..7....",
                    "6..195...",
                    ".98....6.",
                    "8...6...3",
                    "4..8.3..1",
                    "7...2...6",
                    ".6....28.",
                    "...419..5",
                    "....8..79"};

    constructBoard(arr);
    cout<<sudoku()<<endl;
    printBoard();

    


     return 0;
}