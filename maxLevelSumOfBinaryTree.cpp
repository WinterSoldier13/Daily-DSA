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
    
    int maxLevelSum(TreeNode* root) 
    {
        if(root == NULL)
    {
        return 0;
    }

    queue<TreeNode*>q1;
    queue<TreeNode*>q2;

    q1.push(root);
    int c = 0;
    int max_ = root->val;
    int maxLevel = 1;


    while(!q1.empty() or !q2.empty())
    {
        int sum_ = 0;
        if(c%2==0)
        {
            while(!q1.empty())
            {
                TreeNode* curr = q1.front();
                q1.pop();

                sum_+=curr->val;

                if(curr->left != NULL)
                {
                    q2.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q2.push(curr->right);
                }
            }
            cout<<sum_<<endl;
            if(sum_>max_)
            {
                maxLevel = c+1;
                max_ = sum_;
            }

        }
        else
        {
            while(!q2.empty())
            {
                TreeNode* curr = q2.front();
                q2.pop();

                sum_+=curr->val;

                if(curr->left != NULL)
                {
                    q1.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q1.push(curr->right);
                }
            }
                        cout<<sum_<<endl;

            if(sum_>max_)
            {
                maxLevel = c+1;
                max_ = sum_;
            }

        }
        c++;
    }

    return maxLevel;
        
    }
};
