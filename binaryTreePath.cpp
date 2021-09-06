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

class Solution
{
public:

    vector<vector<int>> mothership;
    vector<string> out;

    void __init__()
    {
        mothership.clear();
        out.clear();
    }

    void recurse(TreeNode* root, vector<int> &path)
    {
        if(root == NULL)
        {
            return;
        }
        int val = root->val;
        path.push_back(val);

        if(root->left!=NULL)
        {
            recurse(root->left, path);
            path.pop_back();
        }
        if(root->right!=NULL)
        {
            recurse(root->right, path);
            path.pop_back();
        }
        if(!root->left and !root->right)
        {
            mothership.push_back(path);
        }
    }

    void printPath()
    {
        for(auto path : mothership)
        {
            string s="";
            for(auto c: path)
            {
                cout<<c<<" ";
                s+=to_string(c);
                s+="->";
            }
            s = s.substr(0,s.size() - 2);
            // cout<<s<<endl;
            out.push_back(s);
            cout<<endl;
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        __init__();
        vector<int> path;
        recurse(root, path);
        printPath();
        
        return out;
    }
};