class Solution {
public:
    void replaceO(vector<vector<char>>& board)
    {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j]=='O')
                board[i][j] = 'A';
            }
        }
        
    }
    
    void recurse(vector<vector<char>>& grid, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(i<0 or j<0 or i>=rows or j>=cols or grid[i][j]!='A')
        {
            return;
        }
        grid[i][j] = 'O';
        
        recurse(grid, i-1,j);
        recurse(grid, i,j+1);
        recurse(grid, i+1,j);
        recurse(grid, i,j-1);
        
    }
    
    void replaceEdge(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0;i<cols;i++)
        {
            if(board[0][i] == 'A')
            {
                recurse(board, 0,i);
            }
        }
        for(int i=0;i<cols;i++)
        {
            if(board[rows-1][i] == 'A')
            {
                recurse(board, rows-1,i);
            }
        }
        
        for(int i=0;i<rows;i++)
        {
            if(board[i][0] == 'A')
            {
                recurse(board, i, 0);
            }
        }
        for(int i=0;i<rows;i++)
        {
            if(board[i][cols-1] == 'A')
            {
                recurse(board, i,cols-1);
            }
        }
        
        
    }
    
    
    void replaceA(vector<vector<char>>& board)
    {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i =0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j] == 'A')
                    board[i][j] = 'X';
            }
        }
        
    }
    
    void solve(vector<vector<char>>& board) 
    {
        if(board.size()==0)
            return ;
        
        replaceO(board);
        replaceEdge(board);
        replaceA(board);
        
    }
};