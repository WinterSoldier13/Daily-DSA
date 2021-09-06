/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        int c=0;
        q1.push(root);
        vector<vector<int>> out;
        if(root==NULL)
            return out;
        
        while(!q1.empty() or !q2.empty())
        {
            vector<int> temp;
            if(c%2==0)
            {
                while(!q1.empty())
                {
                    TreeNode* curr = q1.front();
                    q1.pop();
                    temp.push_back(curr->val);
                    if(curr->left!=NULL)
                    {
                        q2.push(curr->left);
                    }
                    if(curr->right!=NULL)
                    {
                        q2.push(curr->right);
                    }
                    
                }
                out.push_back(temp);
                temp.clear();
            }
            else
            {
                while(!q2.empty())
                {
                    TreeNode* curr = q2.front();
                    q2.pop();
                    temp.push_back(curr->val);
                    if(curr->left!=NULL)
                    {
                        q1.push(curr->left);
                    }
                    if(curr->right!=NULL)
                    {
                        q1.push(curr->right);
                    }
                }
                out.push_back(temp);
                temp.clear();
            }
            c++;
        }
        
        
        return out;
        
        
    }
};