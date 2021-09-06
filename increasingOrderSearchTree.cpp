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
    
    TreeNode* newRoot;
    TreeNode* node;
    
    Solution()
    {
        newRoot = new TreeNode();
        node = newRoot;
    }
    
    void inOrder(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        inOrder(root->left);
        
        TreeNode* newNode = new TreeNode();
        newNode->val = root->val;

        node->right = newNode;
        node = node->right;
        
        inOrder(root->right);
        
    }
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        inOrder(root);
        newRoot= newRoot->right;
        
        return newRoot;
        
    }
};
