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
    TreeNode* recurse(vector<int> &arr, int i, int j)
    {
        if(i>j)
            return NULL;
        int middle = i + (j-i)/2;
        TreeNode* node = new TreeNode(arr[middle]);
        node->left = recurse(arr, i,middle-1);
        node->right = recurse(arr, middle+1, j);
        return node;
        
        
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return recurse(nums,0,nums.size()-1);
        
    }
};