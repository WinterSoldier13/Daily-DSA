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
            return i;
    }
    return -1;
}

Node *buildUtil(int in[], int post[], int inStart, int inEnd, int postStart, int postEnd)
{
    int currentRoot = post[postEnd];
    Node *root = new Node(currentRoot);

    int indexInInorder = getIndexInInorder(in, currentRoot, inStart, inEnd);

    int leftSize = indexInInorder - inStart;
    int rightSize = inEnd - indexInInorder;

    if(leftSize == 0)
    {
        root->left = NULL;
    }
    else if(leftSize == 1)
    {
        root->left = new Node(in[inStart]);
    }
    else
    {
        root->left = buildUtil(in, post, inStart, indexInInorder-1, postStart, postStart + leftSize -1);
    }

    if(rightSize == 0)
    {
        root->right = NULL;
    }
    else if(rightSize == 1)
    {
        root->right = new Node(in[inEnd]);
    }
    else
    {
        root->right = buildUtil(in, post, indexInInorder+1, inEnd, postStart + leftSize, postEnd -1);
    }

    return root;    
}

Node *buildTree(int in[], int post[], int n)
{
    if(n == 0)
    {
        return NULL;
    }
    return buildUtil(in, post, 0, n-1, 0, n-1);
}