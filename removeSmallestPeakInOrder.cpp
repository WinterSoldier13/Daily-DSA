#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
// #define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________

struct DLL
{
    int val;
    DLL *prev;
    DLL *next;

    DLL(int x)
    {
        val = x;
        prev = next = NULL;
    }
};

DLL *createDLL(vector<int> &arr, unordered_map<int, DLL *> &hashmap)
{
    int l = arr.size();
    DLL *head = new DLL(-1);
    DLL *temp = head;

    for (auto x : arr)
    {
        DLL *node = new DLL(x);
        hashmap[node->val] = node;
        temp->next = node;
        node->prev = temp;

        temp = temp->next;
    }
    temp->next = NULL;
    head = head->next;
    head->prev = NULL;

    return head;
}
void deleteNode(DLL *node)
{
    if(!node)
        return;
    if (node->prev == NULL and node->next == NULL)
    {
        node = NULL;
        return;
    }
    else if (node->next == NULL)
    {
        node->prev->next = NULL;
        node->prev = NULL;
        return;
    }
    else if (node->prev == NULL)
    {
        node->next->prev = NULL;
        node->next = NULL;
        return;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return;
    }
}
pair<DLL *, DLL *> getLeftAndRight(DLL *node)
{
    return {node->prev, node->next};
}

bool isCrest(DLL *node)
{
    if(!node) return false;
    if (node->next == NULL and node->prev == NULL)
        return true;

    if (node->next == NULL)
    {
        return node->val > node->prev->val;
    }
    if (node->prev == NULL)
    {
        return node->val > node->next->val;
    }
    return node->val > node->next->val and node->val > node->prev->val;
}

vector<int> solve(vector<int> &nums)
{
    vector<int> out;
    int n = nums.size();
    if (n == 0)
        return out;
    if (n == 1)
        return nums;
    if (n == 2)
    {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return nums;
    }
    unordered_map<int, DLL *> hashmap;
    DLL *linkedList = createDLL(nums, hashmap);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> hashset;

    // first I will push all the peaks that exist initially into the minHeap
    if (nums[0] > nums[1])
    {
        minHeap.push(nums[0]);
        hashset.insert(nums[0]);
    }
    if (nums[n - 1] > nums[n - 2])
    {
        minHeap.push(nums[n - 1]);
        hashset.insert(nums[n - 1]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1])
        {
            minHeap.push(nums[i]);
            hashset.insert(nums[i]);
        }
    }

    // top of the minHeap will give me the minimum crest
    // now if I am removing this crest from the array
    // it means that only two elements will be affected
    // one to it's right and other one to it's left

    while (out.size() != n)
    {
        int curr = minHeap.top();
        if (hashset.count(curr))
        {
            hashset.erase(curr);
            out.push_back(curr);
            minHeap.pop();
            auto nextNode = hashmap[curr]->next;
            auto prevNode = hashmap[curr]->prev;
            deleteNode(hashmap[curr]);
            hashmap.erase(curr);

            if (isCrest(prevNode))
            {
                minHeap.push(prevNode->val);
                hashset.insert(prevNode->val);
            }
            if (isCrest(nextNode))
            {
                minHeap.push(nextNode->val);
                hashset.insert(nextNode->val);
            }
        }
        else
        {
            minHeap.pop();
        }
    }

    return out;
}

int main()
{
    fast_cin();
    return 0;
}
