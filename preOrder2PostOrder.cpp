#include <bits/stdc++.h>
using namespace std;

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

int getIndexOfRightSubTree(int pre[], int start, int end, int val)
{
    for(int i=start;i<=end;i++)
    {
        if(pre[i] > val)
        {
            return i;
        }
    }
    return end+1;
}
Node* recurse1(int pre[], int start, int end)
{
    Node* root = new Node(pre[start]);

    int IndexOfRightSubTree = getIndexOfRightSubTree(pre, start, end, root->data);

    int leftSubTreeSize = IndexOfRightSubTree - start - 1;
    int rightSubTreeSize = end - IndexOfRightSubTree + 1;

    if(leftSubTreeSize == 0)
    {
        root->left = NULL;
    }
    else if(leftSubTreeSize == 1)
    {
        root->left = new Node(pre[start+1]);
    }
    else
    {
        root->left = recurse1(pre, start +1, IndexOfRightSubTree - 1);
    }

    if(rightSubTreeSize == 0)
    {
        root->right = NULL;
    }
    else if(rightSubTreeSize == 1)
    {
        root->right = new Node(pre[IndexOfRightSubTree]);
    }
    else
    {
        root->right = recurse1(pre, IndexOfRightSubTree, end);
    }
    return root;
}

void postOrder(Node* root, vector<int> &arr)
{
    if(root == NULL)
    {
        return;
    }

    postOrder(root->left, arr);
    postOrder(root->right, arr);

    arr.push_back(root->data);
}

Node* constructTree(int pre[], int size) 
{
    Node* root = recurse1(pre, 0, size-1);
    return root;
}

int main()
{
    return 0;
}