#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define tiiii tuple<int, int, int, int>

int isPallindrome(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    return s == temp;
}
void dfs(vector<vector<char>> &arr, int i, int j, string s, unordered_multiset<string> &hashset)
{
    int rows = arr.size();
    int cols = arr[0].size();

    if (i < 0 or i >= rows or j < 0 or j >= cols or arr[i][j] == 'A')
    {
        return;
    }
    

    if (i == rows - 1 and j == cols - 1)
    {
        s+=arr[i][j];
        // cout<<s<<endl;
        if (isPallindrome(s))
            hashset.insert(s);
        return;
    }
    char temp = arr[i][j];
    arr[i][j] = 'A';
    s += temp;

    dfs(arr, i + 1, j, s, hashset);
    dfs(arr, i, j + 1, s, hashset);

    arr[i][j] = temp;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int rows, cols;
        cin >> rows >> cols;

        vector<char> temp(cols, ' ');
        vector<vector<char>> arr(rows, temp);
        unordered_multiset<string> hashset;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }

        string s = "";
        dfs(arr, 0, 0, s, hashset);

        // for (auto it = hashset.begin(); it != hashset.end(); it++)
        // {
        //     cout << *it << endl;
        // }

        cout << hashset.size() << endl;
    }
}

// a a a b
// b a a a
// a b b a