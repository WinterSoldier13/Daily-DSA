#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

struct Node
{
    int data;
    Node *left, *right, *parent;
};

Node *getRootNode(Node *node)
{
    Node *root = node;

    while (root->parent)
    {
        root = root->parent;
    }
    return root;
}

Node *findRightSibling(Node *node)
{
    auto root = getRootNode(node);

    if (root == node)
    {
        return;
    }
    queue<Node *> q1;
    queue<Node *> q2;

    int c = 0;

    q1.push(root);

    while (!q1.empty() or !q2.empty())
    {
        bool found = false;
        if (c % 2 == 0)
        {
            while (!q1.empty())
            {
                auto curr = q1.front();
                q1.pop();
                if (found)
                {
                    return curr;
                }
                if (curr == node)
                {
                    found = true;
                }

                if (curr->left)
                {
                    q2.push(curr->left);
                }
                if (curr->right)
                {
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
                if (found)
                {
                    return curr;
                }
                if (curr == node)
                {
                    found = true;
                }

                if (curr->left)
                {
                    q1.push(curr->left);
                }
                if (curr->right)
                {
                    q1.push(curr->right);
                }
            }
        }
        c++;
    }
    return NULL;
}