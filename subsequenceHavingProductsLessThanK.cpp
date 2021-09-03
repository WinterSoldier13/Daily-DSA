#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________

// just memorize this solution, or make the 2d table with index and currentProduct
int recurse(vector<int> &arr, int index, int currentProduct, const int k)
{
    if(index == 0)
    {
        return 0;
    }
    if(currentProduct * arr[index-1] < k)
    {
        return 1 + recurse(arr, index-1, currentProduct*arr[index - 1], k) +recurse(arr, index-1, currentProduct, k);
    }
    else
    {
        return recurse(arr, index-1, currentProduct, k);
    }
}


int main()
{
    fast_cin();

    vector<int> arr{4,8,7,2};
    int k = 50;
    cout<<recurse(arr, arr.size(), 1, k)<<endl;
    return 0;
}
