#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

bool bottomAndRight(vector<vector<char>> &arr, pii ptr1, pii ptr2)
{
    int n = arr.size();
    if (ptr1.first >= n or ptr1.second >= n or ptr2.first >= n or ptr2.second >= n)
    {
        return false;
    }
    int ptr1End = ptr2.first;
    int ptr2End = ptr1.second;
    pii backupOne = ptr1;
    pii backupTwo = ptr2;

    while (ptr1.first < ptr1End and ptr2.second < ptr2End and arr[ptr1.first][ptr1.second] == arr[ptr2.first][ptr2.second] and arr[ptr1.first][ptr1.second] == 'X')
    {
        ptr1.first += 1;
        ptr2.second += 1;
    }

    if (ptr1 == ptr2 and arr[ptr1.first][ptr1.second] == 'X')
    {
        return true;
    }
    return false;
}

int upAndLeft(vector<vector<char>> &arr, int i, int j)
{
    pii ptr1 = {i, j};
    pii ptr2 = {i, j};

    int n = arr.size();
    int maxSize = 0;

    while (ptr1.second < n and ptr2.first < n and (arr[ptr1.first][ptr1.second] == arr[ptr2.first][ptr2.second]) and (arr[ptr2.first][ptr2.second] == 'X'))
    {
        ptr1.second += 1;
        ptr2.first += 1;
        if (bottomAndRight(arr, ptr1, ptr2))
        {
            maxSize = max(maxSize, ptr2.first - i + 1);
        }
    }
    return maxSize;
}

void solve(vector<vector<char>> arr)
{
    int maxSize = 0;
    bool atleastOneX = false;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i][j] == 'X')
            {
                atleastOneX = true;
                maxSize = max(maxSize, upAndLeft(arr, i, j));
            }
        }
    }

    if (maxSize == 0 and atleastOneX)
    {
        cout << 1 << endl;
        return;
    }

    cout << maxSize << endl;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<char>> arr(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        // for (auto x : arr)
        // {
        //     for (auto c : x)
        //         cout << c << " ";
        //     cout << endl;
        // }

        solve(arr);
    }

    return 0;
}

// 1
// 4
// X X X O X O X X X X X O X O X X