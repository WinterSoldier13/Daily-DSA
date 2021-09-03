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


class Solution
{
public:
	vector<vector<int>> levelOrder(Node *root)
	{
		vector<vector<int>> mothership;
        if(root == NULL)
        {
            return mothership;
        }

		queue<Node *> q1;
		queue<Node *> q2;
		int c = 0;

		q1.push(root);

		while (!q1.empty() or !q2.empty())
		{
			vector<int> temp;
			if (c % 2 == 0)
			{
				while (!q1.empty())
				{
					Node *curr = q1.front();
					q1.pop();

					temp.push_back(curr->val);

					for (Node *nodes : curr->children)
					{
						q2.push(nodes);
					}
				}
				mothership.push_back(temp);
				temp.clear();
			}
			else
			{
				while (!q2.empty())
				{
					Node *curr = q2.front();
					q2.pop();

					temp.push_back(curr->val);

					for (Node *nodes : curr->children)
					{
						q1.push(nodes);
					}
				}
				mothership.push_back(temp);
				temp.clear();
			}
			c++;
		}
		return mothership;
	}
};