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
};

Node *getNextInOrder(Node *root)
{
    Node *curr = root;
    while (curr and curr->left)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }

    if (x < root->data)
    {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        // this part takes care of 1 child or no child condition, just return the child...
        // incase of no child it will return the NULL child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }



        // this part takes care of the two child condition
        // replace the value of the current child with its inorder successor
        // i.e the leftmost root of the rightmost subtree
        // delete that inorder succesor recursively
        else
        {
            Node *temp = getNextInOrder(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}