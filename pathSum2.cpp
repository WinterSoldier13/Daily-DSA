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
    
    int SUM;
    int currentSum;
    
    void recursion(TreeNode* root, vector<int> &path)
    {
        if(root == NULL)
        {
            return;
        }
        
        path.push_back(root->val);
        currentSum+=root->val;
        
        if(root->right == NULL and root->left == NULL and currentSum == SUM)
        {
            mothership.push_back(path);
        }
        
        if(root->left !=NULL)
        {
            recursion(root->left, path);
            path.pop_back();
            currentSum-=root->left->val;
        }
        
        if(root->right != NULL)
        {
            recursion(root->right, path);
            path.pop_back();
            currentSum-= root->right->val;
        }
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        SUM = sum;
        currentSum = 0;
        if(root==NULL)
            return mothership;
        vector<int> temp;
        recursion(root,temp);
        vector<vector<int>> out = mothership;
        mothership.clear();
        
        return out; 
        
        
    }
};
