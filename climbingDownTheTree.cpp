
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class Solution {
    public:
    int max_;
    void recurse(Tree* root, int sum)
    {
        if(root == NULL)
        {
            return;
        }
        sum+=root->val;
        
        if(root->left == NULL and root->right == NULL)
        {
            max_ = max(max_ , sum);
            return;
        }
        if(root->left != NULL)
        {
            recurse(root->left, sum);
        }
        if(root->right!=NULL)
        {
            recurse(root->right, sum);
        }
        
    }
    int solve(Tree* root) 
    {
        int sum = 0;
        max_ = 0;
        if(root == NULL)
        {
            return max_;
        }
        recurse(root, sum);
        return max_;
    }
};