#include <bits/stdc++.h>
using namespace std;
#define Node node

/* A binary tree node has data, pointer to left child  
and a pointer to right child */
class node  
{  
    public: 
    int data;  
    node *left;  
    node *right;  
};  
  
// A utility function to create a node  
node* newNode (int data)  
{  
    node* temp = new node(); 
  
    temp->data = data;  
    temp->left = temp->right = NULL;  
  
    return temp;  
}  
  
// A recursive function to construct Full from pre[]. preIndex is used  
// to keep track of index in pre[].  
node* constructTreeUtil (vector<int> pre, int* preIndex,  
                                int low, int high, int size)  
{  
    // Base case  
    if (*preIndex >= size || low > high)  
        return NULL;  
  
    // The first node in preorder traversal is root. So take the node at  
    // preIndex from pre[] and make it root, and increment preIndex  
    node* root = newNode ( pre[*preIndex] );  
    *preIndex = *preIndex + 1;  
  
    // If the current subarry has only one element, no need to recur  
    if (low == high)  
        return root;  
  
    // Search for the first element greater than root  
    int i;  
    for ( i = low; i <= high; ++i )  
        if ( pre[ i ] > root->data )  
            break;  
  
    // Use the index of element found in preorder to divide  
        // preorder array in two parts. Left subtree and right subtree  
    root->left = constructTreeUtil ( pre, preIndex, *preIndex,  
                                         i - 1, size );  
    root->right = constructTreeUtil ( pre, preIndex, i, high, size );  
  
    return root;  
}  
  
// The main function to construct BST from given preorder traversal.  
// This function mainly uses constructTreeUtil()  
node *constructTree (vector<int> pre, int size)  
{  
    int preIndex = 0;  
    return constructTreeUtil (pre, &preIndex, 0, size - 1, size);  
}  
  
// A utility function to print inorder traversal of a Binary Tree  
void printInorder (node* node)  
{  
    if (node == NULL)  
        return;  
    printInorder(node->left);  
    cout<<node->data<<" ";  
    printInorder(node->right);  
}  
  
// Driver program to test above functions  
Node* constructTree4me (vector<int> pre)  
{  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    node *root = constructTree(pre, size);  
  
    cout<<"Inorder traversal of the constructed tree: \n";  
    printInorder(root);  
  
    return root;  
}  

vector<vector<Node *>> mothership;

void findNode(Node *root, int val, vector<Node *> &path)
{
    if (root == NULL)
    {
        return;
    }

    int curr = root->data;

    if (curr == val)
    {
        mothership.push_back(path);
        return;
    }
    if (root->left != NULL)
    {
        findNode(root->left, val, path);
        path.pop_back();
    }
    if (root->right != NULL)
    {
        findNode(root->right, val, path);
        path.pop_back();
    }
}

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    vector<Node *> temp;
    findNode(root, n1, temp);
    temp.clear();
    findNode(root, n2, temp);

    if (mothership.size() < 2)
    {
        return NULL;
    }

    vector<Node*> path1 = mothership[0];
    vector<Node*> path2 = mothership[1];

    int i = 0;
    int j = 0;

    while (path1[i]->data == path2[j]->data and i < path1.size() and j < path2.size())
    {
        i++;
        j++;
    }
    return path1[--i]->data;
}


int main()
{
    // The function requires 3 things
    // 1. A vector int
    // 2. A int a
    // 3. A int b

    vector<int> arr{1,23};
    Node* root = constructTree4me(arr);
    return LCA(root, 2, 3);
    
}