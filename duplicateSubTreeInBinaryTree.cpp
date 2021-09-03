#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

bool flag;
void recurse(Node *root, unordered_map<int, vector<Node *>> &hashmap)
{
    if (root == NULL)
    {
        return;
    }
    recurse(root->left, hashmap);
    recurse(root->right, hashmap);
    hashmap[root->data].push_back(root);
}

bool similarTree(Node *root1, Node *root2)
{
    if (root1 == NULL and root2 == NULL)
        return true;
    if (root1 == NULL or root2 == NULL)
        return false;
    
    return (root1->data == root2->data) and similarTree(root1->left, root2->left) and similarTree(root1->right, root2->right);
}

void inOrder(Node *root, unordered_map<int, vector<Node *>> &hashmap)
{
    if (root == NULL or flag)
    {
        return;
    }
    inOrder(root->left, hashmap);

    if (hashmap[root->data].size() > 1)
    {
        for (auto node : hashmap[root->data])
        {
            if (root == node or (root->left == NULL and root->right == NULL))
            {
                continue;
            }
            if(similarTree(root, node))
            {
                flag = true;
                return;
            }
        }
    }

    inOrder(root->right, hashmap);
}

bool dupSub(Node *root)
{
    flag = false;
    unordered_map<int, vector<Node*>> hashmap;
    recurse(root, hashmap);
    inOrder(root, hashmap);

    return flag;
}

int main()
{
    return 0;
}