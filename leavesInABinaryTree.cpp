/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// return the Height of the given Binary Tree
int height(Node* root)
{
   // Your code here
   if(root == NULL)
   {
       return 0;
   }
   return 1+max(height(root->left), height(root->right));
}

