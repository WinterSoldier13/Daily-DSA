/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) 
    {
        if(root == NULL)
            return 0;
        queue<Node*> q1;
        queue<Node*> q2;
        
        int c =0;
        
        int maxHeight = 0;
        
        q1.push(root);
        
        while(!q1.empty() or !q2.empty())
        {
            if(c%2 == 0)
            {
                while(!q1.empty())
                {
                    auto curr = q1.front();
                    q1.pop();
                    
                    for(auto nodes: curr->children)
                    {
                        q2.push(nodes);
                    }
                }
                
            }
            else
            {
                while(!q2.empty())
                {
                    auto curr = q2.front();
                    q2.pop();
                    
                    for(auto nodes: curr->children)
                    {
                        q1.push(nodes);
                    }
                }
                
            }
            c++;
            maxHeight++;
        }
        return maxHeight;
        
    }
};
