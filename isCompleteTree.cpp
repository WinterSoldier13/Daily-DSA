class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int nullFound = 0;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                nullFound = 1;
            }
            else
            {
                if (nullFound)
                {
                    return 0;
                }
                else
                {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return 1;
    }
};
