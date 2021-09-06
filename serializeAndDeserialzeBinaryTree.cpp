/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preOrder(TreeNode* root, string &s)
    {
        if(root == NULL)
        {
            s+="1.3,";
            return;
        }
        int val = root->val;
        ostringstream str1;
        str1<<val;
        string valToString = str1.str();
        s+=valToString;
        s+=",";
        preOrder(root->left, s);
        preOrder(root->right, s);
    }
    
    
    string serialize(TreeNode* root)
    {
        string s="";
        preOrder(root, s);
        s = s.substr(0,s.size()-1);
        cout<<s<<endl;

        return s;
        
    }

    // Decodes your encoded data to tree.
    int index=0;
    TreeNode* helper(vector<double> data)
    {
        if(index>=data.size() or data[index]==1.3)
        {
            index++;
            return NULL;
        }
        TreeNode* node = new TreeNode(data[index++]);
        
        node->left = helper(data);
        node->right = helper(data);
        
        return node;
    }
    TreeNode* deserialize(string data)
    {
        vector<double> arr;
        int l = data.size();
        string str="";
        
        for(int i=0;i<l;i++)
        {
            char ch = data[i];

            
            if(ch!=',')
                str+=ch;
            else
            {
                if(str == "1.3")
                {
                    arr.push_back(stod(str));
                    str="";
                }
                else{
                arr.push_back(stoi(str));
                str="";
                }
            }
        }
        
        for(auto x:arr)
            cout<<x<<endl;
        index = 0;
        
        return helper(arr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));