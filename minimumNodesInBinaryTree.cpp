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
    set<int> hashset;
    void recurse(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        recurse(root->left);
        
        hashset.insert(root->val);
        
        recurse(root->right);
        
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        hashset.clear();
        recurse(root);
        
        auto it = hashset.begin();
        it++;
        
        if(hashset.size() <2)
            return -1;
        return *it;
        
    }
};