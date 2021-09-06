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
// #define pii pair<int, int>
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

// https://binarysearch.com/problems/K-Subsequence

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
};

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class Solution
{
private:

    int ans;
    void changeOfPlan(Tree *root, vector<int> &path)
    {
        if (!root)
        {
            return;
        }
        if (path.size() > 2)
        {
            if (path[path.size() - 2] % 2 == 0)
            {
                ans+=root->val;
            }
        }
        path.push_back(root->val);

        if (root->left)
        {
            changeOfPlan(root->left, path);
            path.pop_back();
        }
        if (root->right)
        {
            changeOfPlan(root->right, path);
            path.pop_back();
        }
    }

public:
    int solve(Tree *root)
    {
        int totalLevels_ = 1;
        totalLevels(root, 1, totalLevels_);
        cout << "Total Levels: " << totalLevels_ << endl;
        if (totalLevels_ <= 2)
        {
            return 0;
        }
        ans = 0;
        vector<int> path;
        changeOfPlan(root, path);
        return ans;
    }
};
int solve(Tree *root)
{
    Solution ob;
    return ob.solve(root);
}

int main()
{
    return 0;
}
