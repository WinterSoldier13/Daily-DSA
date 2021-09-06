
//function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Should convert tree to its mirror */
void mirror(Node *node)
{
    // Your Code Here

    if (node == NULL)
        return;

    Node *left = node->left;
    Node *right = node->right;
    Node *temp = left;

    node->left = right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}