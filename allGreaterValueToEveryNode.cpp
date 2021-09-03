#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inOrder(Node* root, vector<int> &arr)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

void recurse(Node* root, unordered_map<int, int> &hashmap)
{
    if(root == NULL)
    {
        return;
    }
    recurse(root->left, hashmap);
    root->data += hashmap[root->data];
    recurse(root->right, hashmap);
}

// modify the BST and return its root
Node* modify(Node *root)
{
    vector<int> arr;
    inOrder(root, arr);
    reverse(arr.begin(), arr.end());
    vector<int> temp;
    int cumulative = 0;
    for(int i=0;i<arr.size();i++)
    {
        temp.push_back(cumulative);
        cumulative+=arr[i];
    }
    unordered_map<int, int> hashmap;
    for(int i=0;i<arr.size();i++)
    {
        hashmap[arr[i]] = temp[i];
    }
    recurse(root, hashmap);
    return root;
}


int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;


        long long int leftPtr = INT64_MIN;
        long long int rightPtr = INT64_MAX;
        bool fail = false;
        while(n--)
        {
            char dirn;
            long long int val;
            cin>>dirn>>val;

            if(dirn == 'L')
            {
                rightPtr = val - 1;
            }
            else
            {
                leftPtr = val + 1;
            }
            if(leftPtr > rightPtr)
            {
                fail = true;
                break;
            }
        }
        if(fail)
        {
            cout<<-1<<endl;
            continue;
        }

        long long int ans = (rightPtr - leftPtr + 1);
        cout<<ans<<endl;
    }

    return 0;
}
