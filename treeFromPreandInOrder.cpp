#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int getIndexInInorder(int in[], int val, int inStart, int inEnd)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (in[i] == val)
        {
            return i;
        }
    }
    return -1;
}

Node *buildUtil(int in[], int pre[], int inStart, int inEnd, int preStart, int preEnd)
{
    int currentRootVal = pre[preStart];
    int rootIndex = getIndexInInorder(in, currentRootVal, inStart, inEnd);

    int leftSubTreeSize = rootIndex - inStart;
    int rightSubTreeSize = inEnd - rootIndex;

    Node *root = new Node(currentRootVal);

    if (leftSubTreeSize == 0)
    {
        root->left = NULL;
    }
    else if (leftSubTreeSize == 1)
    {
        root->left = new Node(in[inStart]);
    }
    else
    {
        root->left = buildUtil(in, pre, inStart, rootIndex - 1, preStart + 1, preStart + leftSubTreeSize);
    }

    if (rightSubTreeSize == 0)
    {
        root->right = NULL;
    }
    else if (rightSubTreeSize == 1)
    {
        root->right = new Node(in[inEnd]);
    }
    else
    {
        root->right = buildUtil(in, pre, rootIndex + 1, inEnd, preEnd - rightSubTreeSize + 1, preEnd);
    }

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    if (n == 0)
    {
        return NULL;
    }
    return buildUtil(in, pre, 0, n - 1, 0, n - 1);
}