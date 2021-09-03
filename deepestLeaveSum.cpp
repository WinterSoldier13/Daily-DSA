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
    
    
    int levelOrder(TreeNode* root)
    {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        int c=0;
        
        vector<vector<int>> mothership;
        
        q1.push(root);
        
        while(!q1.empty() or !q2.empty())
        {
            vector<int> temp;
            if(c%2 == 0)
            {
                while(!q1.empty())
                {
                    TreeNode* curr = q1.front();
                    q1.pop();

                    
                    temp.push_back(curr->val);
                    
                    if(curr->left!=NULL)
                    {
                        q2.push(curr->left);
                    }
                    if(curr->right!=NULL)
                    {
                        q2.push(curr->right);
                    }
                }
                mothership.push_back(temp);
            }
            else
            {
                while(!q2.empty())
                {
                    TreeNode* curr = q2.front();
                    q2.pop();

                    
                    temp.push_back(curr->val);
                    
                    if(curr->left!=NULL)
                    {
                        q1.push(curr->left);
                    }
                    if(curr->right!=NULL)
                    {
                        q1.push(curr->right);
                    }
                }
                mothership.push_back(temp);
            }
            c++;
        }
        
        int sum_ = 0;
        
        for(auto x: mothership[mothership.size()-1])
            sum_+=x;
        return sum_;
    }
    
    
    
    
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        return levelOrder(root);
        
    }
};
