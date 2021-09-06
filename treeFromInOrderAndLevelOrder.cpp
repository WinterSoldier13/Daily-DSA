#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>
struct Node
{
    int key;
    struct Node *left, *right;
};

Node *newNode(int x)
{
    return NULL;
}

int getFirstMatchingVal(int inorder[], int levelOrder[], int iStart, int iEnd, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = iStart; j <= iEnd; j++)
        {
            if (inorder[j] == levelOrder[i])
            {
                return j;
            }
        }
    }
    return -1;
}

Node *buildHelper(int inorder[], int levelOrder[], int iStart, int iEnd, int n)
{
    int rootIndex = getFirstMatchingVal(inorder, levelOrder, iStart, iEnd, n);

    Node *root = newNode(inorder[rootIndex]);

    int leftSubTreeSize = rootIndex - iStart;
    int rightSubTreeSize = iEnd - rootIndex;

    if(leftSubTreeSize == 0)
    {
        root->left = NULL;
    }
    else if(leftSubTreeSize == 1)
    {
        root->left = newNode(inorder[rootIndex-1]);
    }
    else
    {
        root->left = buildHelper(inorder, levelOrder, iStart, iStart+leftSubTreeSize-1, n);
    }

    if(rightSubTreeSize == 0)
    {
        root->right = NULL;
    }
    else if(rightSubTreeSize == 1)
    {
        root->right = newNode(inorder[rootIndex+1]);
    }
    else
    {
        root->right = buildHelper(inorder, levelOrder, rootIndex+1, iEnd, n);
    }

    return root;
}

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n)
{
    if (n == 0)
    {
        return 0;
    }

    return buildHelper(inorder, levelOrder, iStart, iEnd, n);
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

        Solution ob;
        ob.solve(n);
    }

    return 0;
}