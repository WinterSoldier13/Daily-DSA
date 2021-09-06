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

class ZippedIterator
{
private:
    bool turn;
    int ptr1, ptr2, l1, l2;
    vector<int> arr1, arr2;

public:
    ZippedIterator(vector<int> &a, vector<int> &b)
    {
        turn = true;
        ptr1 = 0;
        ptr2 = 0;
        l1 = a.size();
        l2 = b.size();
        arr1 = a;
        arr2 = b;
    }

    int next()
    {
        turn = !turn;
        if (!turn)
        {
            if (ptr1 < l1)
                return arr1[ptr1++];
            return arr2[ptr2++];
        }
        if (turn)
        {
            if (ptr2 < l2)
                return arr2[ptr2++];
            return arr1[ptr1++];
        }
        return -1;
    }

    bool hasnext()
    {
        return ptr1 < l1 or ptr2 < l2;
    }
};
int main()
{
    return 0;
}