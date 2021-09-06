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
	vector<int> goodNodesArr;
	void recursion(TreeNode *root, vector<int> &path, int maxEle)
	{
		if (root == NULL)
			return;

		path.push_back(root->val);

		if (root->val >= maxEle)
			goodNodesArr.push_back(root->val);
		maxEle = max(maxEle, root->val);

		if (root->left != NULL)
		{
			recursion(root->left, path, maxEle);
			path.pop_back();
		}
		if (root->right != NULL)
		{
			recursion(root->right, path, maxEle);
			path.pop_back();
		}
	}

	int goodNodes(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		vector<int> path;
		recursion(root, path, INT32_MIN + 1);
		int l = goodNodesArr.size();
		goodNodesArr.clear();
		return l;
	}
};
