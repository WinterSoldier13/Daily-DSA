#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
private:
    int maxV;
    int recurse(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftSum = recurse(root->left);
        int rightSum = recurse(root->right);

        int max1 = max(max(leftSum, rightSum) + root->data, root->data);

        int max2 = max(max1, leftSum + rightSum + root->data);

        maxV = max(maxV, max2);

        return max1; 
    }

public:
    int solve(Node *root)
    {
        maxV = INT_MIN;

        maxV = max(maxV, recurse(root));

        cout<<maxV<<endl;

        return maxV;
    }
};

int findMaxSum(Node *root)
{
    Solution ob;
    ob.solve(root);
}

int main()
{
    fast_cin();

    return 0;
}