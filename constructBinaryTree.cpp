
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node *insertLevelOrder(int arr[], Node *root, int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        Node *temp = newNode(arr[i]);
        if (arr[i] == -1)
        {
            temp = NULL;
        }
        root = temp;

        // insert left child
        if (root != NULL)
            root->left = insertLevelOrder(arr,
                                          root->left, 2 * i + 1, n);

        // insert right child
        if (root != NULL)
            root->right = insertLevelOrder(arr,
                                           root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to print tree nodes in
// InOrder fashion
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Driver program to test above function
int main()
{
    int arr[] = {2,3,4,5,6,7,8,9,-1,10,11,-1,-1,-1,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = insertLevelOrder(arr, root, 0, n);
    inOrder(root);
}