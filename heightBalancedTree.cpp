// A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 

// This function should return tree if passed  tree 
// is balanced, else false. 
int height(Node* root)
{
    if(root == 0)
    {
        return 0;
    }

    return 1+max(height(root->left), height(root->right));
}


bool isBalanced(Node *root)
{
    if(root == NULL)
    {
        return true;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if((abs(leftHeight-rightHeight)<=1) and isBalanced(root->left) and isBalanced(root->right))
    {
        return true;
    }
    return false;
}
