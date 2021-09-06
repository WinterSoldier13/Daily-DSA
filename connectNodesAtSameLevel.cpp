

#include<bits/stdc++.h>
using namespace std;
#define next nextRight

void connect(Node *root)
{
    // Your Code Here
       if(root == NULL)
       return ;
        
       Node* head = root;

       queue<Node*> q1;
       queue<Node*> q2;
       int c = 0;

       q1.push(root);

       while(!q1.empty() or !q2.empty())
       {
           vector<Node*> temp;

           if(c%2 == 0)
           {
               while(!q1.empty())
               {
                   Node* curr = q1.front();
                   q1.pop();
                   temp.push_back(curr);

                   if(curr->left)
                   {
                       q2.push(curr->left);
                   }
                   if(curr->right)
                   {
                       q2.push(curr->right);
                   }
               }
               for(int i=0;i<temp.size()-1;i++)
               {
                   temp[i]->nextRight = temp[i+1];
               }
               temp[temp.size()-1]->nextRight = NULL;
               temp.clear();

           }
           else
           {
                while(!q2.empty())
               {
                   Node* curr = q2.front();
                   q2.pop();
                   temp.push_back(curr);

                   if(curr->left)
                   {
                       q1.push(curr->left);
                   }
                   if(curr->right)
                   {
                       q1.push(curr->right);
                   }
               }
               for(int i=0;i<temp.size()-1;i++)
               {
                   temp[i]->nextRight = temp[i+1];
               }
               temp[temp.size()-1]->nextRight = NULL;
               temp.clear();
           }
           c++;

       }
        return ;
    
}
