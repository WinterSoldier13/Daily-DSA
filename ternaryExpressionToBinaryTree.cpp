#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define pii pair<int, int>
#define endl '\n'

struct Node
{
    char data;
    Node *left, *right;
    Node(char x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *recurse(string str, int start, int end)
{
    if (start >= end)
    {
        return NULL;
    }

    Node *root = new Node(str[start - 1]);

    root->right = new Node(str[end + 1]);

    if (end - start == 2)
    {
        root->left = new Node(str[start + 1]);
    }
    else
        root->left = recurse(str, start + 2, end - 2);

    return root;
}

void preOrder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

Node *convertExpression(string str, int i)
{
    int ptr1 = 1;
    int ptr2 = str.size() - 2;
    Node *root = recurse(str, ptr1, ptr2);

    // preOrder(root);
    // cout << endl;
    return root;
}

int main()
{
    fast_cin();

    string str = "a?b?c:d:e";
    convertExpression(str, 0);
    return 0;
}