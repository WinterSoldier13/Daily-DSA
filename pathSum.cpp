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
    
    int SUM;
    bool found;
    int currentSum;
    
    void __init__(int sum)
    {
        SUM = sum;
        found = false;
        currentSum = 0;
    }
    
    
    
    void recursion(TreeNode* root)
    {
        if(root == NULL or found)
            return;
        
        currentSum+=root->val;
        
        if(root->left == NULL and root->right==NULL)
        {
            if(currentSum == SUM)
                found = true;
        }
        
        if(root->left != NULL)
        {
            recursion(root->left);
            currentSum-=root->left->val;
        }
        
        if(root->right != NULL)
        {
            recursion(root->right );
            currentSum-=root->right->val;
        }
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) 
    {
        __init__(sum);
        
        recursion(root);
        return found;
    }
};
