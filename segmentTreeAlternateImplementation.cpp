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

class SegmentTree
{
public:
    vector<int> segmentTree;
    vector<int> arr;
    void __init__(vector<int> &a)
    {
        segmentTree.clear();
        arr.clear();
        arr = a;
        int n = arr.size();
        segmentTree = vector<int>(4 * n + 1, 0);
    }

    void constructTree(int index, int start, int end)
    {
        if (start == end)
        {
            segmentTree[index] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;

        constructTree(2 * index + 1, start, mid);
        constructTree(2 * index + 2, mid + 1, end);

        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
    }


    int getSum(int index, int start, int end, int rangeX, int rangeY)
    {
        if (rangeX > rangeY)
            return 0;

        if (rangeX == start and rangeY == end)
        {
            return segmentTree[index];
        }
        int mid = start + (mid - start) / 2;

        return getSum(2 * index + 1, start, mid, rangeX, min(rangeY, mid)) + getSum(2 * index + 2, mid + 1, end, max(rangeX, mid + 1), rangeY);
    }

    void update(int index, int start, int end, int indexToUpdate, int valToAppend)
    {
        if (start == end)
        {
            segmentTree[index] += valToAppend;
            return;
        }

        int mid = start + (end - start) / 2;
        if (indexToUpdate <= mid)
        {
            update(2 * index + 1, start, mid, indexToUpdate, valToAppend);
        }
        else
        {
            update(2 * index + 2, mid + 1, end, indexToUpdate, valToAppend);
        }
        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
    }

    void solve(vector<int> &a)
    {
        __init__(a);
        constructTree(0, 0, a.size() - 1);
    }
};


void recurse(vector<pair<int,int>> &arr, int index, SegmentTree &sTree, int &minSum)
{
    if(index == 0)
    {
        return;
    }
    
}

int main()
{
    fast_cin();

    int n = 8;
    int m = 8;
    vector<pair<int, int>> arr{{0, 2}, {1, 3}, {1, 2}, {3, 4}, {4, 5}, {4, 7}, {5, 8}, {5, 6}};
    vector<int> temp(n,0);
    SegmentTree sTree;
    sTree.solve(temp);




    return 0;
}
