#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

struct Node
{
    int data;
    Node *left, *right;
};

vector<vector<int>> mothership;
int A;
int B;

void recurse(Node *root, vector<int> &path, int end)
{
    if (!root)
    {
        return;
    }
    path.push_back(root->data);
    if (root->data == end)
    {
        mothership.push_back(path);
        return;
    }

    if (root->left)
    {
        recurse(root->left, path, end);
        path.pop_back();
    }
    if (root->right)
    {
        recurse(root->right, path, end);
        path.pop_back();
    }
}

int findDist(Node *root, int a, int b)
{
    if (root == NULL)
    {
        return 0;
    }
    mothership.clear();
    vector<int> path;
    recurse(root, path, a);
    path.clear();
    recurse(root, path, b);

    vector<int> path1 = mothership[0];
    vector<int> path2 = mothership[1];

    int ptr1 = 0;
    int ptr2 = 0;

    while (path1[ptr1] == path2[ptr2])
    {
        ptr1++;
        ptr2++;
    }
    int l1 = path1.size();
    int l2 = path2.size();

    return (l1 - ptr1 - 1) + (l2 - ptr2 - 1) + 2;
}
