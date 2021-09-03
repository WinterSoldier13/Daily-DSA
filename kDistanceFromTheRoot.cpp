#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define tiiii tuple<int, int, int, int>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
    queue<Node *> q1;
    queue<Node *> q2;
    vector<int> out;
    int c = 0;

    q1.push(root);

    while (!q1.empty() or !q2.empty())
    {
        vector<int> temp;
        if (c % 2 == 0)
        {
            while (!q1.empty())
            {
                auto curr = q1.front();
                q1.pop();

                temp.push_back(curr->data);

                if (curr->left)
                {
                    q2.push(curr->left);
                }
                if (curr->right)
                {
                    q2.push(curr->right);
                }
            }
            if (c == k)
            {
                out = temp;
                break;
            }
        }
        else
        {
            while (!q2.empty())
            {
                auto curr = q2.front();
                q2.pop();

                temp.push_back(curr->data);

                if (curr->left)
                {
                    q1.push(curr->left);
                }
                if (curr->right)
                {
                    q1.push(curr->right);
                }
            }
            if (c == k)
            {
                out = temp;
                break;
            }
        }
        c++;
    }
    return out;
}