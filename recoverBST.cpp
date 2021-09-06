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
    
    TreeNode* firstEle;
    TreeNode* secondEle;
    TreeNode* prevEle;
    
    void init()
    {
        firstEle = NULL;
        secondEle = NULL;
        prevEle = NULL;
    }
    
    void inOrder(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        inOrder(root->left);
        
        
        
        if(prevEle!=NULL)
        {
            if(prevEle->val >= root->val)
            {
                if(firstEle==NULL)
                    firstEle = prevEle;
                secondEle = root;
            }
        }
        prevEle = root;
        
        
        
        inOrder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        init();
        if(root==NULL)
            return ;
        inOrder(root);
        
        cout<<firstEle->val<<" "<<secondEle->val;
        swap(firstEle, secondEle);
        
        int temp = firstEle->val;
        firstEle->val = secondEle->val;
        secondEle->val = temp;
        return;
    }
};