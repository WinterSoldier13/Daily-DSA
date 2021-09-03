#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Index like : x,y
    map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> hashset;
    Solution()
    {
    }

    void recurse(TreeNode *root, int x, int y)
    {
        if (root == NULL)
        {
            return;
        }
        int val = root->val;
        auto height_Value = make_pair(y, val);
        hashset[x].push(height_Value);

        recurse(root->left, x - 1, y + 1);
        recurse(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> out;
        if (root == NULL)
        {
            return out;
        }
        recurse(root, 0, 0);

        for (auto it = hashset.begin(); it != hashset.end(); it++)
        {
            auto pq = it->second;
            vector<int> temp;

            while (!pq.empty())
            {
                temp.push_back(pq.top().second);
                pq.pop();
            }
            out.push_back(temp);
        }
        hashset.clear();
        return out;
    }
};

int main()
{
    map<int, int> x;
    x[-10] = -10;
    x[-2] = -2;
    x[1] = 1;
    x[-34] = -34;
    x[10] = 10;

    for (auto it = x.begin(); it != x.end(); it++)
    {
        cout << it->second << endl;
    }

    return 0;
}