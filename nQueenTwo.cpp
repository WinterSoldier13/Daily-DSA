class Solution {
public:
    vector<string> board;
int count;

void createBoard(int n)
{
    string s="";
    for(int i=0;i<n;i++)
    {
        s+=".";
    }
    for(int i=0;i<n;i++)
    {
        board.push_back(s);
    }
    count = 0;
}

void printBoard()
{
    for(auto x: board)
    cout<<x<<endl;
}

bool isSafe(int row, int col)
{
    int rows = board.size();
    int cols = rows;

    //Check col
    for(int i=0;i<rows;i++)
    {
        if(board[i][col] == 'Q')
        {
            return false;
        }
    }

    //check row
    for(int i=0;i<cols;i++)
    {
        if(board[row][i] == 'Q')
        {
            return false;
        }
    }

    //Check -45 diagonal 1
    int i = row; int j=col;
    while(true)
    {
        if(i<0 or j<0)
        {
            break;
        }
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }
    //Check -45 diagonal 2
    i = row; j=col;
    while(true)
    {
        if(i>=rows or j>=rows)
        {
            break;
        }
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j++;
    }
    //Check 45 diagonal 1
    i = row; j=col;
    while(true)
    {
        if(i>=rows or j<0)
        {
            break;
        }
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }
    //Check 45 diagonal 2
    i = row; j=col;
    while(true)
    {
        if(i<0 or j>=cols)
        {
            break;
        }
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}


bool place(int col)
{
    if(col>=board.size())
    {
        count++;
        return true;
    }

    for(int i=0;i<board.size();i++)
    {
        if(isSafe(i,col))
        {
            board[i][col] = 'Q';
            if(place(col+1))
            {
                
            }
            board[i][col] = '.';
        }
    }

    return false;

}




    int totalNQueens(int n) 
    {
            createBoard(n);
    place(0);
    // printBoard();
    
    return count;
        
    }
};