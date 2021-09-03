
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */



#include<bits/stdc++.h>
using namespace std;

void printSpiral(Node *root)
{
    vector<vector<int>> mothership;

    if(!root)
    return;

    queue<Node*> q1;
    queue<Node*> q2;

    q1.push(root);
    int c = 0;

    while(!q1.empty() or !q2.empty())
    {
        vector<int> temp;
        
        if(c%2 == 0)
        {
            while(!q1.empty())
            {
                Node* curr = q1.front();
                q1.pop();
                temp.push_back(curr->data);
                if(curr->left)
                {
                    q2.push(curr->left);
                    
                }
                if(curr->right)
                {
                    q2.push(curr->right);
                    
                }
            }
            reverse(temp.begin(), temp.end());
            mothership.push_back(temp);
            temp.clear();
        }
        else
        {
            while(!q2.empty())
            {
                Node* curr = q2.front();
                q2.pop();
                temp.push_back(curr->data);
                if(curr->left)
                {
                    q1.push(curr->left);
                    
                }
                if(curr->right)
                {
                    q1.push(curr->right);
                    
                }
            }
            mothership.push_back(temp);
            temp.clear();
        }
        c++;
    }
    for(auto x: mothership)
    {
        for(int k: x)
        cout<<k<<" ";
    }

    
}
