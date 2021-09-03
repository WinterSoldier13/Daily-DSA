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

vector<int> solve2(vector<int> &arr)
{
    int l = arr.size();
    if (l == 0)
        return arr;

    vector<int> left(l, 0);
    for (int i = 1; i < l; i++)
    {
        int count = 0;

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                count++;
            }
        }
        left[i] = count;
    }

    printArr(left);

    unordered_map<int, int> hashmap_index;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (int i = 0; i < l; i++)
    {
        minHeap.push({arr[i], i});
    }
    vector<int> out;

    while (!minHeap.empty())
    {
        auto curr = minHeap.top();
        minHeap.pop();

        int ele = curr.first;
        int index = curr.second;

        out.push_back(index - left[index]);
    }

    printArr(out);
    return out;
}

class Solution
{
private:
    vector<int> SegmentTree;
    vector<int> arr;

    int constructSegmentTree(int start, int end, int index)
    {
        if (start == end)
        {
            SegmentTree[index] = 0;
            return 0;
        }
        int l = end - start + 1;

        if (l % 2 == 0)
        {
            SegmentTree[index] = constructSegmentTree(start, start + (l / 2) - 1, 2 * index + 1) + constructSegmentTree(start + (l / 2), end, 2 * index + 2);
        }
        else
        {
            SegmentTree[index] = constructSegmentTree(start, start + ((l + 1) / 2) - 1, 2 * index + 1) + constructSegmentTree(start + ((l + 1) / 2), end, 2 * index + 2);
        }

        return SegmentTree[index];
    }

    void update(int i, int start, int end, int index)
    {
        if (i < start)
            return;
        if (i > end)
            return;
        if (start == end)
        {
            SegmentTree[index]++;
            return;
        }
        int l = end - start + 1;

        if (l % 2 == 0)
        {
            SegmentTree[index]++;
            update(i, start, start + (l / 2) - 1, 2 * index + 1);
            update(i, start + (l / 2), end, 2 * index + 2);
        }
        else
        {
            SegmentTree[index]++;
            update(i, start, start + ((l + 1) / 2) - 1, 2 * index + 1);
            update(i, start + ((l + 1) / 2), end, 2 * index + 2);
        }
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
            SegmentTree[index] += valueToAppend;
            return;
        }

        else
        {
            SegmentTree[index] += valueToAppend;
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

    int getSum(int start, int end, int currI, int currJ, int index)
    {
        if (currJ < start)
            return 0;
        if (currI > end)
            return 0;

        if (start <= currI and currJ <= end)
        {
            return SegmentTree[index];
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

public:
    Solution(vector<int> &a)
    {
        arr = a;
        int n = arr.size();
        SegmentTree = vector<int>(4 * n, 0);

        constructSegmentTree(0, n - 1, 0);
    }

    vector<int> solve(vector<int> &arr)
    {
        int l = arr.size();
        if (l == 0)
            return arr;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < l; i++)
        {
            minHeap.push({arr[i], i});
        }
        vector<int> out;

        while (!minHeap.empty())
        {
            auto curr = minHeap.top();
            minHeap.pop();
            int ele = curr.first;
            int index = curr.second;

            if (index == 0)
            {
                out.push_back(0);
                update(index, 0, l - 1, 0);
                continue;
            }

            int poppedElements = getSum(0, index - 1, 0, l - 1, 0);
            out.push_back(index - poppedElements);

            update(index, 0, l - 1, 0);
            // recursiveUpdate(index, 1, 0, l-1, 0);
        }
        return out;
    }
};

vector<int> solve(vector<int> &arr)
{
    int l = arr.size();
    
    Solution s(arr);
    return s.solve(arr);
}

int main()
{
    fast_cin();

    vector<int> arr{3, 5, 1, 4, 2};
    auto ans = solve(arr);
    printArr(ans);
    return 0;
}
