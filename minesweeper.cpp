class Solution {
public:

int getAdjacentMines(vector<vector<char>> &board, int x, int y)
{
    int minesCount = 0;
    int rows = board.size();
    int cols = board[0].size();

    vector<int> dirX = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dirY = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < 8; i++)
    {
        int X = x+dirX[i];
        int Y = y+dirY[i];
        if ( X>=0 and Y>=0 and X<rows and Y<cols and  board[X][Y] == 'M')
        {
            minesCount++;
        }
    }
    return minesCount;
}

void dfs(vector<vector<char>> &board, int i, int j)
{
    int rows = board.size();
    int cols = board[0].size();

    if (i < 0 or j < 0 or i >= rows or j >= cols or board[i][j] != 'E')
    {
        return;
    }

    int minesCount = getAdjacentMines(board, i, j);
    if (minesCount == 0)
    {
        board[i][j] = 'B';
    }
    else
    {
        board[i][j] = minesCount + '0';
        return;
    }
    dfs(board, i - 1, j);
    dfs(board, i - 1, j + 1);
    dfs(board, i, j + 1);
    dfs(board, i + 1, j + 1);
    dfs(board, i + 1, j);
    dfs(board, i + 1, j - 1);
    dfs(board, i, j - 1);
    dfs(board, i - 1, j - 1);
}

vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
{
    int x = click[0];
    int y = click[1];

    if (board[x][y] == 'M')
    {
        board[x][y] = 'X';
        return board;

    }

    int minesCount = getAdjacentMines(board, x, y);

    if (minesCount > 0)
    {
        board[x][y] = minesCount + '0';
        return board;
    }
    if (minesCount == 0)
    {
        dfs(board, x, y);
    }
    
    auto temp = board;
    board.clear();
    
    return temp;
}
};