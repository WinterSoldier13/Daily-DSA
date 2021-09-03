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
    
    
    void inOrderLoop(TreeNode* root, vector<int>& out)
    {
        if(root==NULL)
        {
            return;
        }
        
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        
        while(curr!=NULL || stack.empty()== false)
        {
            
            while(curr!=NULL)
            {
                stack.push(curr);
                curr = curr->left;
            }
            
            curr = stack.top();
            stack.pop();
            out.push_back(curr->val);
            curr = curr->right;
            
        }
    }
    
    
    void inOrder(TreeNode* root, vector<int> &out)
    {
        if(root==NULL)
        {
            return;
        }
        
        inOrder(root->left, out);
        out.push_back(root->val);
        inOrder(root->right, out);
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> out;
        inOrderLoop(root,out);
        return out;
        
    }
};