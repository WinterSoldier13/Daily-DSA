#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// https://www.interviewbit.com/problems/capture-regions-on-board/

void replaceO(vector<vector<string>> &board)
{
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == "O")
                board[i][j] = "A";
        }
    }
}

void recurse(vector<vector<string>> &grid, int i, int j)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] != "A")
    {
        return;
    }
    grid[i][j] = "O";

    recurse(grid, i - 1, j);
    recurse(grid, i, j + 1);
    recurse(grid, i + 1, j);
    recurse(grid, i, j - 1);
}

void replaceEdge(vector<vector<string>> &board)
{
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < cols; i++)
    {
        if (board[0][i] == "A")
        {
            recurse(board, 0, i);
        }
    }
    for (int i = 0; i < cols; i++)
    {
        if (board[rows - 1][i] == "A")
        {
            recurse(board, rows - 1, i);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        if (board[i][0] == "A")
        {
            recurse(board, i, 0);
        }
    }
    for (int i = 0; i < rows; i++)
    {
        if (board[i][cols - 1] == "A")
        {
            recurse(board, i, cols - 1);
        }
    }
}

void replaceA(vector<vector<string>> &board)
{
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == "A")
                board[i][j] = "X";
        }
    }
}

void print(vector<vector<string>> &grid)
{
    for (auto x : grid)
    {
        for (auto c : x)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<string>> &board)
{

    replaceO(board);
    print(board);
    replaceEdge(board);
    print(board);
    replaceA(board);
    print(board);
}

int main()
{
    vector<vector<char>> arr{{'X', 'X', 'X', 'X'},
                             {'X', 'O', 'O', 'X'},
                             {'X', 'X', 'O', 'X'},
                             {'X', 'O', 'X', 'X'}};

    vector<vector<char>> arr2{{'X', 'O', 'X'},
                              {'O', 'X', 'O'},
                              {'X', 'O', 'X'}};

    vector<vector<string>> arr3{{"X", "O", "O", "X", "X", "X", "O", "X", "O", "O"}, {"X", "O", "X", "X", "X", "X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "O", "X", "X", "X", "X", "X"}, {"X", "O", "X", "X", "X", "O", "X", "X", "X", "O"}, {"O", "X", "X", "X", "O", "X", "O", "X", "O", "X"}, {"X", "X", "O", "X", "X", "O", "O", "X", "X", "X"}, {"O", "X", "X", "O", "O", "X", "O", "X", "X", "O"}, {"O", "X", "X", "X", "X", "X", "O", "X", "X", "X"}, {"X", "O", "O", "X", "X", "O", "X", "X", "O", "O"}, {"X", "X", "X", "O", "O", "X", "O", "X", "X", "O"}};
    print(arr3);

    solve(arr3);
}