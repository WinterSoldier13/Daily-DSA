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

class MutableRangeSum
{
private:
    vector<int> segmentTree;
    int n;
    int constructTree(vector<int> &arr, int start, int end, int index)
    {
        if (start > end)
            return 0;
        if (start == end)
        {
            segmentTree[index] = arr[start];
            return arr[start];
        }
        int l = end - start + 1;
        if (l % 2 == 0)
        {
            segmentTree[index] = constructTree(arr, start, start + l / 2 - 1, 2 * index + 1) + constructTree(arr, start + l / 2, end, 2 * index + 2);
        }
        else
        {
            segmentTree[index] = constructTree(arr, start, start + (l + 1) / 2 - 1, 2 * index + 1) + constructTree(arr, start + (l + 1) / 2, end, 2 * index + 2);
        }
        return segmentTree[index];
    }

    int getSum(int start, int end, int currI, int currJ, int index)
    {
        if (currJ < start)
            return 0;
        if (currI > end)
            return 0;

        if (start <= currI and currJ <= end)
        {
            return segmentTree[index];
        }

        else
        {
            int l = currJ - currI + 1;
            if (l % 2 == 0)
                return getSum(start, end, currI, currI + (l / 2) - 1, 2 * index + 1) + getSum(start, end, currI + (l / 2), currJ, 2 * index + 2);
            else
                return getSum(start, end, currI, currI + (l + 1) / 2 - 1, 2 * index + 1) + getSum(start, end, currI + (l + 1) / 2, currJ, 2 * index + 2);
        }
        return -1;
    }

    void recursiveUpdate(int indexToUpdate, int valueToAppend, int currI, int currJ, int index)
    {
        if (index < 0)
            return;
        if (indexToUpdate < currI or indexToUpdate > currJ)
        {
            return;
        }
        if (currI == currJ)
        {
            segmentTree[index] += valueToAppend;
            return;
        }
        else
        {
            // cout<<"Updating "<<index<<endl;
            segmentTree[index] += valueToAppend;
            int l = currJ - currI + 1;
            if (l % 2 == 0)
            {
                recursiveUpdate(indexToUpdate, valueToAppend, currI, currI + (l / 2) - 1, 2 * index + 1);
                recursiveUpdate(indexToUpdate, valueToAppend, currI + (l / 2), currJ, 2 * index + 2);
            }
            else
            {
                recursiveUpdate(indexToUpdate, valueToAppend, currI, currI + (l + 1) / 2 - 1, 2 * index + 1);
                recursiveUpdate(indexToUpdate, valueToAppend, currI + (l + 1) / 2, currJ, 2 * index + 2);
            }
        }
    }
    vector<int> tempArr;

public:
    MutableRangeSum(vector<int> &arr)
    {
        tempArr = arr;
        n = arr.size();
        segmentTree.clear();
        segmentTree = vector<int>(4 * n, INT_MIN);
        constructTree(arr, 0, n - 1, 0);
        // printArr(segmentTree);
    }

    int total(int start, int end)
    {
        return getSum(start, end - 1, 0, n - 1, 0);
    }

    void update(int idx, int val)
    {
        int change = val - tempArr[idx];
        tempArr[idx] = val;
        recursiveUpdate(idx, change, 0, n - 1, 0);
    }
};

int main()
{
    fast_cin();

    vector<int> arr{0, 1, 2, 3, 4};
    MutableRangeSum ob(arr);

    cout << ob.total(0, 2) << endl;
    ob.update(1, 4);
    cout << ob.total(1, 4) << endl;
    ob.update(1, 5);
    cout << ob.total(1, 5) << endl;
    return 0;
}
