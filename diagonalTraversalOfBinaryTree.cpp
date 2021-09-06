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

#define slope 1
void recurse(Node *root, map<int, vector<int>> &hashmap, int x, int y)
{
    if (root == NULL)
    {
        return;
    }
    recurse(root->left, hashmap, x - 1, y + 1);

    int yIntercept = y - slope * x;
    hashmap[yIntercept].push_back(root->data);

    recurse(root->right, hashmap, x + 1, y + 1);
}

vector<int> diagonal(Node *root)
{
    vector<int> out;
    if (root == NULL)
    {
        return out;
    }

    map<int, vector<int>> hashmap;
    recurse(root, hashmap, 0, 0);

    for(int i=0;i<hashmap.size();i++)
    {
        int sum = 0;
        for(auto x: hashmap[i])
        {
            sum+=x;
        }
        out.push_back(sum);
    }

    return out;
}

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Driver program
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    auto ans = diagonal(root);
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}