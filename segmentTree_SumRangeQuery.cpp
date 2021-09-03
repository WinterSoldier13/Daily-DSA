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

    // method to create segment tree recursively
    int constructTree(vector<int> &arr, int start, int end, int index)
    {
        // arr -> the array in the input
        // start -> starting index of range
        // end -> ending index of range (INCLUDED)
        // index -> current index in segmentTree array where we need to store the sum of given range from [start, end]
        //          For left subtree indexLeft = 2*index +1
        //          For right subtree indexRight = 2*index +2

        if (start > end)
            return 0;

        // if the range reduces to a single point then return the value of that element only
        if (start == end)
        {
            segmentTree[index] = arr[start];
            return arr[start];
        }

        // get the length of current range, useful to split the current range
        int l = end - start + 1;
        if (l % 2 == 0)
        {
            // if the length is even then evenly split the array, that is equal number of elements go both side
            segmentTree[index] = constructTree(arr, start, start + l / 2 - 1, 2 * index + 1) + constructTree(arr, start + l / 2, end, 2 * index + 2);
        }
        else
        {
            // if the length is odd then left half should have one more element than the right side, so split it that way
            segmentTree[index] = constructTree(arr, start, start + (l + 1) / 2 - 1, 2 * index + 1) + constructTree(arr, start + (l + 1) / 2, end, 2 * index + 2);
        }
        // return the value recursively
        return segmentTree[index];
    }

    int getSum(int start, int end, int currI, int currJ, int index)
    {
        // start -> given from input 
        // end -> given from input
        // currI -> equ to start in constructTree function
        // currJ -> equ to end in constructTree function

        // if the index which we get during recursion is totally outside the input range return 0
        if (currJ < start)
            return 0;
        if (currI > end)
            return 0;

        // if the index during recursion completely lies inside the input range then return the value from the segment tree
        if (start <= currI and currJ <= end)
        {
            return segmentTree[index];
        }

        else // if none of the above req are satisfied then return the sum of left subTree and right subTree
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

        // if the index is not contained in the current range of index then do nothing
        if (indexToUpdate < currI or indexToUpdate > currJ)
        {
            return;
        }

        // base case return from here
        if (currI == currJ)
        {
            segmentTree[index] += valueToAppend;
            return;
        }

        // recursively call for the left and the right nodes from the current node
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
        tempArr = arr; // storing the array for later use
        n = arr.size();

        segmentTree.clear();
        segmentTree = vector<int>(4 * n, INT_MIN); // 4*n is a safe size of segment tree to create for an array of size n

        // this method creates the segment tree recursively
        // jump to this method to see how
        constructTree(arr, 0, n - 1, 0);
        // printArr(segmentTree);
    }

    int total(int start, int end)
    {
        // we are passing -1 because the question wants [starts, end)
        return getSum(start, end - 1, 0, n - 1, 0);
    }

    void update(int idx, int val)
    {
        // calculate the change in value (it may be +ve or -ve)
        int change = val - tempArr[idx];
        tempArr[idx] = val;

        // recursively update all the nodes in the segment tree which contain the given index
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
