#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// return the head of the DLL and remove those node from the tree as well.
Node *convertToDLL(Node *root)
{
    Node *dllHead = new Node(10);
    Node *dllTemp = dllHead;

    vector<int> tempArr;
    queue<Node *> q1;
    queue<Node *> q2;

    int c = 0;

    q1.push(root);

    while (!q1.empty() or !q2.empty())
    {
        if (c % 2 == 0)
        {
            while (!q1.empty())
            {
                auto curr = q1.front();
                q1.pop();

                if (curr->left != NULL)
                {
                    if (curr->left->left == NULL and curr->left->right == NULL)
                    {
                        tempArr.push_back(curr->left->data);
                        curr->left = NULL;
                    }
                    else
                        q2.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    if (curr->right->left == NULL and curr->right->right == NULL)
                    {
                        tempArr.push_back(curr->right->data);
                        curr->right = NULL;
                    }
                    else
                        q2.push(curr->right);
                }
            }
        }
        else
        {
            while (!q2.empty())
            {
                auto curr = q2.front();
                q2.pop();

                if (curr->left != NULL)
                {
                    if (curr->left->left == NULL and curr->left->right == NULL)
                    {
                        tempArr.push_back(curr->left->data);
                        curr->left = NULL;
                    }
                    else
                        q1.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    if (curr->right->left == NULL and curr->right->right == NULL)
                    {
                        tempArr.push_back(curr->left->data);
                        curr->right = NULL;
                    }
                    else
                        q1.push(curr->right);
                }
            }
        }
        c++;
    }
    c = 0;
    for (auto x : tempArr)
    {
        Node *node = new Node(x);
        if (c == 0)
        {
            dllTemp->right = node;
            node->left = NULL;
            dllHead = node;
            dllTemp = node;
        }
        else
        {
            dllTemp->right = node;
            node->left  = dllTemp;
            dllTemp = node; 
        }
    }
    dllTemp->right = NULL;

    return dllHead;
}