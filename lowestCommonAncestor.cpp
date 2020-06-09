

#include<bits/stdc++.h>
using namespace std;

vector<vector<Node*>> mothership;

void findNode(Node* root, int val, vector<Node*> &path)
{
    if(root == NULL)
    {
        return;
    }

    int curr = root->data;

    if(curr == data)
    {
        mothership.push_back(path);
        return;
    }
    if(root->left!=NULL)
    {
        findNode(root->left, val, path);
        path.pop_back();
    }
    if(root->right!=NULL)
    {
        findNode(root->right, val, path);
        path.pop_back();
    }
}

Node* LCA(Node *root, int n1, int n2)
{
    if(!root)
    return NULL;

    vector<Node*> temp;
    findNode(root, n1, temp);
    temp.clear();
    findNode(root, n2, temp);

    if(mothership.size()<2)
    {
        return NULL;
    }

    vector<int> path1 = mothership[0];
    vector<int> path2 = mothership[1];

    int i=0;
    int j=0;

    while(path1[i] == path2[j] and i<path1.size() and j<path2.size())
    {
        i++;
        j++;
    }
    return one[--i];
}