
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // Lets Do levelorder yeeaaah
        Node *ptr = root;
        queue<Node *> q1;
        queue<Node *> q2;
        int c = 0;

        q1.push(ptr);

        while (!q1.empty() or !q2.empty())
        {
            if (c % 2 == 0)
            {
                int first = 1;
                while (!q1.empty())
                {
                    auto curr = q1.front();
                    q1.pop();
                    if (first)
                    {
                        first = 0;
                        ptr = curr;
                    }
                    else
                    {
                        ptr->next = curr;
                        ptr = ptr->next;
                    }

                    if (curr->left != NULL)
                    {
                        q2.push(curr->left);
                    }
                    if (curr->right != NULL)
                    {
                        q2.push(curr->right);
                    }
                }
                ptr->next = NULL;
            }
            else
            {
                int first = 1;
                while (!q2.empty())
                {
                    auto curr = q2.front();
                    q2.pop();
                    if (first)
                    {
                        first = 0;
                        ptr = curr;
                    }
                    else
                    {
                        ptr->next = curr;
                        ptr = ptr->next;
                    }

                    if (curr->left != NULL)
                    {
                        q1.push(curr->left);
                    }
                    if (curr->right != NULL)
                    {
                        q1.push(curr->right);
                    }
                }
                ptr->next = NULL;
            }
            c++;
        }
        return root;
    }
};