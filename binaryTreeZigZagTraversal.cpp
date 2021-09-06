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
    vector<vector<int>> mothership;
    int c;
    void traverse(TreeNode* root)
    {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        q2.push(root);
        vector<int> temp;
        
        while(!q1.empty() or !q2.empty())
        {
            if(c==0)
                q2.pop();
            if(c%2==0)
            {
                while(!q1.empty())
                {
                    TreeNode* current = q1.front();
                    temp.push_back(current->val);
                    if(current->left!=NULL)
                        q2.push(current->left);
                    if(current->right!=NULL)
                        q2.push(current->right);
                    q1.pop();
                    
                }
                mothership.push_back(temp);
                temp.clear();
                c++;
            }
            else
            {
                while(!q2.empty())
                {
                    TreeNode* current = q2.front();
                    temp.push_back(current->val);
                    if(current->left!=NULL)
                        q1.push(current->left);
                    if(current->right!=NULL)
                        q1.push(current->right);
                    q2.pop();
                    
                }
                reverse(temp.begin(), temp.end());
                mothership.push_back(temp);
                temp.clear();
                c++;
                
            }
            
        }
        
        
    }
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        c=0;
        vector<vector<int>> out;
        if(root==NULL)
            return out;
            
        traverse(root);
        out = mothership;
        mothership.clear();
        return out;
        
        
    }
};