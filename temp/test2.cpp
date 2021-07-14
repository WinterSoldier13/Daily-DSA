#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define endl "\n"

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node* generateBST(vector<int> inOrder, int start, int end)
{
    if (start > end) return NULL;
 
    int mid = (start + end) / 2;
    Node* node = new Node(inOrder[mid]);

    node->left = generateBST(inOrder, start, mid - 1);
    node->right = generateBST(inOrder, mid + 1, end);

    return node;
}

int bSearch(vector<int> &arr, int k)
{
	int ans = -1;
	int start = 0;
	int end = arr.size()-1;
	while(start<=end)
	{
		int mid = start + (end-start)/2;

		if(arr[mid] >= k)
		{
			ans = mid;
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}
	}
	return ans;
}

void printPre(Node* root)
{
	if(!root) return;
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
}

int main()
{
	fast_cin();
	int n,k;
	cin>> n >> k;

    vector<int> in(n,0);
    vector<int> pre(n,0);
	for(int i=0;i<n;i++) cin>>in[i];
	for(int i=0;i<n;i++) cin>>pre[i];

	// if it is a Inorder of a BST then it is already sorted
	int index = bSearch(in, k);
	if(index == -1)
	{
		// all the values are less than k
		for(int i=0;i<n;i++)
			cout<<in[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<pre[i]<<" ";
		cout<<endl;
		cout<<endl;
		cout<<endl;
	}
	else if(index == 0)
	{
		// all the values are greater than or equal to k
		cout<<endl;
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<in[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<pre[i]<<" ";
		cout<<endl;
	}

	else
	{
		// print of first tree
		for(int i=0;i<index;i++)
			cout<<in[i]<<" ";
		cout<<endl;
		printPre(generateBST(in, 0, index-1));
        cout<<endl;

		// print of the second tree
		for(int i=index;i<n;i++)
			cout<<in[i]<<" ";
		cout<<endl;

		printPre(generateBST(in, index, n-1));
		cout<<endl;
	}

	return 0;
}