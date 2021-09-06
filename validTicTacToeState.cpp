#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

vector<vector<pair<int, int>>> possibleSolutions{
    {{0, 0}, {0, 1}, {0, 2}}, //first row
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {1, 0}, {2, 0}}, // first col
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}}, //first diagonal
    {{0, 2}, {1, 1}, {2, 0}}  // second diagonal

};

int isValidCombination(vector<string> &board, char ch)
{
    for (auto x : possibleSolutions)
    {
        auto curr = x;
        auto cord1 = x[0];
        auto cord2 = x[1];
        auto cord3 = x[2];

        if (board[cord1.first][cord1.second] == ch and board[cord2.first][cord2.second] == ch and board[cord3.first][cord3.second] == ch)
        {
            return 1;
        }
    }
    return 0;
}

class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int countX = 0;
        int countO = 0;

        for (auto x : board)
        {
            for (auto c : x)
            {
                if (c == 'X')
                {
                    countX++;
                }
                else if (c == 'O')
                {
                    countO++;
                }
            }
        }
        // cout<<countX<<" "<<countO<<endl;

        if ((countX == countO) or (countX == countO + 1))
        {
            int isXwinning = isValidCombination(board, 'X');
            int isOwinning = isValidCombination(board, 'O');

            if (isXwinning)
            {
                if (isOwinning)
                {
                    return 0;
                }
                return countX == countO + 1;
            }
            if (isOwinning)
            {
                if (isXwinning)
                {
                    return 0;
                }
                return countX == countO;
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    vector<string> arr{"XOX", "O O", "XOX"};
    Solution ob;
    cout << ob.validTicTacToe(arr) << endl;
}