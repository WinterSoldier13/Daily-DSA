#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool recurse(vector<vector<char>>& grid, const string &word, int l, int i, int j)
{
    int rows = grid.size();
    int cols = grid[0].size();
    if(l==0)
    {
        return true;
    }
    if(i<0 or j<0 or i>=rows or j>=cols or grid[i][j]!=word[l-1])
    {
        return false;
    }
    grid[i][j] = '.';

    bool top = recurse(grid,word, l-1,i-1,j);
    bool right = recurse(grid,word, l-1,i,j+1);
    bool down = recurse(grid,word, l-1,i+1,j);
    bool left = recurse(grid,word, l-1,i,j-1);

    grid[i][j] = word[l-1];

    return top or right or down or left;
}


bool exist(vector<vector<char>>& board, string word) 
{
    if(board.size() == 0)
    {
        return false;
    }
    if(word.size() ==0)
    {
        return false;
    }
    int rows = board.size();
    int cols = board[0].size();
    bool found = false;

    for(int i=0;i<rows;i++)
    {
        for(int j =0;j<cols;j++)
        {
            if(board[i][j] == word[word.size()-1])
            {
                found = recurse(board, word, word.size(),i,j);
            }
            if(found)
            {
                return found;
            }
        }
    }
    return found;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
    vector<string> out;
    if(board.size()==0 or words.size()==0)
    {
        return out;
    }
    
    for(string str: words)
    {
        if(exist(board, str))
        {
            out.push_back(str);
        }
    }
    return out;
    
}

int main()
{
    vector<vector<char>> grid2{{'o','a','a','n'},
                               {'e','t','a','e'},
                               {'i','h','k','r'},
                               {'i','f','l','v'}};
    vector<string> arr{"oath","pea","eat","rain"};

    for(auto x: findWords(grid2, arr))
    {
        cout<<x<<endl;
    }


    return 0;
}