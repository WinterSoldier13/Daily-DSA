
#include<bits/stdc++.h>
using namespace std;

void leftView(Node *root)
{
    vector<vector<int>> mothership;

    queue<Node*> q1;
    queue<Node*> q2;

    if(root == NULL)
    {
        return;
    }
    int c = 0;

    q1.push(root);

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

                if(curr->left != NULL)
                {
                    q2.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q2.push(curr->right);
                }
            }
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

                if(curr->left != NULL)
                {
                    q1.push(curr->left);
                }
                if(curr->right != NULL)
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
        cout<<x[0]<<endl;
    }
   
}