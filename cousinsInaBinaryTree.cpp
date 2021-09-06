#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct childNode
{
public:
	TreeNode *node;
	TreeNode *parent;
	childNode() : node(nullptr), parent(nullptr) {}
};

bool isCousins(TreeNode *root, int x, int y)
{
	if (root == NULL)
	{
		return false;
	}
	queue<childNode *> q1;
	queue<childNode *> q2;
	int c = 0;

	childNode *child = new childNode();
	child->node = root;
	child->parent = nullptr;
	vector<childNode *> level;

	q1.push(child);

	while (!q1.empty() or !q2.empty())
	{
		vector<childNode *> temp;
		bool activate = false;
		if (c % 2 == 0)
		{
			while (!q1.empty())
			{
				childNode *curr = q1.front();
				q1.pop();

				temp.push_back(curr);

				if (curr->node->left != NULL)
				{
					child = new childNode();
					child->parent = curr->node;
					child->node = curr->node->left;

					q2.push(child);
				}
				if (curr->node->right != NULL)
				{
					child = new childNode();
					child->parent = curr->node;
					child->node = curr->node->right;

					q2.push(child);
				}

				if (curr->node->val == x or curr->node->val == y)
				{
					activate = true;
				}
			}
			if (activate)
			{
				level = temp;
				break;
			}
			else
			{
				temp.clear();
			}
		}
		else
		{
			while (!q2.empty())
			{
				childNode *curr = q2.front();
				q2.pop();

				temp.push_back(curr);

				if (curr->node->left != NULL)
				{
					child = new childNode();
					child->parent = curr->node;
					child->node = curr->node->left;

					q1.push(child);
				}
				if (curr->node->right != NULL)
				{
					child = new childNode();
					child->parent = curr->node;
					child->node = curr->node->right;

					q1.push(child);
				}

				if (curr->node->val == x or curr->node->val == y)
				{
					activate = true;
				}
			}
			if (activate)
			{
				level = temp;
				break;
			}
			else
			{
				temp.clear();
			}
		}
		c++;
	}
	bool xFound = false;
	bool yFound = false;
	childNode *xNode;
	childNode *yNode;
	for (childNode *z : level)
	{
		if (xFound and yFound)
			break;
		if (z->node->val == x)
		{
			xFound = true;
			xNode = z;
		}
		if (z->node->val == y)
		{
			yFound = true;
			yNode = z;
		}
	}

	if (xFound and yFound)
	{
		return xNode->parent->val != yNode->parent->val;
	}
	else
	{
		return false;
	}

	return false;
}

int main()
{
	TreeNode *root = NULL;
	isCousins(root, 1, 0);
}
