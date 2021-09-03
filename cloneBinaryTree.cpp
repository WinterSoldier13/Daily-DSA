#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *random;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        random = NULL;
    }
};

void recurse1(Node *root, unordered_map<Node *, Node *> &hashmap)
{
    if (root == NULL)
    {
        return;
    }
    recurse1(root->left, hashmap);
    hashmap[root] = new Node(root->data);
    recurse1(root->right, hashmap);
}

void recurse2(Node *root, unordered_map<Node *, Node *> &hashmap)
{
    if (root == NULL)
    {
        return;
    }
    recurse2(root->left, hashmap);

    if (root->left)
    {
        hashmap[root]->left = hashmap[root->left];
    }
    else
    {
        hashmap[root]->left = NULL;
    }

    if (root->right)
    {
        hashmap[root]->right = hashmap[root->right];
    }
    else
    {
        hashmap[root]->right = NULL;
    }

    if(root->random)
    {
        hashmap[root]->random = hashmap[root->random];
    }
    else
    {
        hashmap[root]->random = NULL;
    }

    recurse2(root->right, hashmap);
}

Node *cloneTree(Node *tree)
{
    unordered_map<Node *, Node *> hashmap;

    recurse1(tree, hashmap);
    recurse2(tree, hashmap);
    return hashmap[tree];
}

int main()
{
    return 0;
}