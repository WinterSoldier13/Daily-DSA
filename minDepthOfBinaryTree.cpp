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
    int minDepth1;
    
    void __init__()
    {
        minDepth1 = INT32_MAX;
    }
    
    void recursion(TreeNode* root, vector<int> &path)
    {
        if(root == NULL)
            return;
        
        path.push_back(root->val);
        
        if(root->left==NULL and root->right==NULL)
        {
            minDepth1 = min(minDepth1, (int)path.size());
            
            for(auto c: path)
                cout<<c<<" ";
            cout<<endl;
        }
        
        if(root->left !=NULL)
        {
            recursion(root->left, path);
            path.pop_back();
        }
        
        if(root->right !=NULL)
        {
            recursion(root->right, path);
            path.pop_back();
        }
    }
    
    
    int minDepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        __init__();
        vector<int> temp;
        recursion(root, temp);
        return minDepth1;
        
    }
};
