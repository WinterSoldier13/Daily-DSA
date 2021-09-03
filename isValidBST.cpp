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
    
    void inOrderLoop(TreeNode* root, vector<int> &out)
    {
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        
        while(curr!=NULL or !stack.empty())
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
    
    bool isValidBST(TreeNode* root) 
    {
        vector<int> out;
        if(root==NULL)
        {
            return true;
        }
        inOrderLoop(root, out);
        
        for(int i=0;i<out.size()-1;i++)
        {
            if(out[i]>=out[i+1])
            {
                return false;
            }
        }
        return true;
        
    }
};