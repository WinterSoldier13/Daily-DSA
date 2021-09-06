#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
private:
    unordered_map<int, Node *> unreadHashmap;
    unordered_map<int, Node *> readHashmap;
    unordered_map<int, Node *> trashHashmap;
    Node *unreadQHead;
    Node *readHead;
    Node *trashHead;
    Node *tempRead;
    Node *tempTrash;
    void __init__()
    {
        unreadHashmap.clear();
        readHashmap.clear();
        trashHashmap.clear();
    }

    void createUnreadQ(int n)
    {
        unreadQHead = new Node(-1);
        Node *temp = unreadQHead;
        for (int i = 1; i <= n; i++)
        {
            Node *node = new Node(i);
            unreadHashmap[i] = node;
            temp->next = node;
            node->prev = temp;
            temp = temp->next;
        }
    }

    void createReadQ()
    {
        readHead = new Node(-1);
        tempRead = readHead;
        tempRead->prev = NULL;
    }

    void createTrashQ()
    {
        trashHead = new Node(-1);
        tempTrash = trashHead;
    }

    void moveFromUnread2Read(int n)
    {
        Node *mssg = unreadHashmap[n];

        mssg->prev->next = mssg->next;
        mssg->next->prev = mssg->prev;

        mssg->prev = tempRead;
        mssg->next = NULL;

        tempRead->next = mssg;
        tempRead = tempRead->next;

        unreadHashmap.erase(n);

        readHashmap[n] = mssg;
    }

    void moveFromRead2Trash(int n)
    {
        Node *mssg = readHashmap[n];

        mssg->prev->next = mssg->next;
        mssg->next->prev = mssg->prev;

        mssg->prev = tempTrash;
        mssg->next = NULL;

        tempTrash->next = mssg;
        tempTrash = tempTrash->next;

        readHashmap.erase(n);

        trashHashmap[n] = mssg;
    }

    void moveFromUnread2Trash(int n)
    {
        Node* mssg = unreadHashmap[n];

        mssg->prev->next = mssg->next;
        mssg->next->prev = mssg->prev;

        mssg->prev = tempTrash;
        mssg->next = NULL;

        tempTrash->next = mssg;
        tempTrash = tempTrash->next;

        unreadHashmap.erase(n);
        trashHashmap[n] = mssg;
    }

    void moveFromTrash2Read(int n)
    {
        Node* mssg  = trashHashmap[n];

        mssg->prev->next = mssg->next;
        mssg->next->prev = mssg->prev;

        mssg->prev = tempRead;
        mssg->next = NULL;

        tempRead->next = mssg;
        tempRead = tempRead->next;

        trashHashmap.erase(n);
        readHashmap[n] = mssg;
    }

    void printUnread()
    {
        Node* temp = unreadQHead;

        while (temp)
        {
            if(temp->data != -1)
            {
                cout<<temp->data<<" ";
            }
            temp = temp->next;
        }
        cout<<endl;
        return;
    }
    void printRead()
    {
        Node* temp = readHead;

        while (temp)
        {
            if(temp->data != -1)
            {
                cout<<temp->data<<" ";
            }
            temp = temp->next;
        }
        cout<<endl;

        return;
    }
    void printTrash()
    {
        Node* temp = trashHead;

        while (temp)
        {
            if(temp->data != -1)
            {
                cout<<temp->data<<" ";
            }
            temp = temp->next;
        }
        cout<<endl;

        return;
    }

public:
    void solve(int n, vector<pair<int, int>> &queries)
    {
        __init__();
        createUnreadQ(n);
        createReadQ();
        createTrashQ();

        for(auto x: queries)
        {
            if(x.first == 1)
            {
                moveFromUnread2Read(x.second);
            }
            else if(x.first == 2)
            {
                moveFromRead2Trash(x.second);
            }
            else if(x.first == 3)
            {
                moveFromUnread2Trash(x.second);
            }
            else
            {
                moveFromTrash2Read(x.second);
            }
        }
        printUnread();
        printRead();
        printTrash();
    }
};

int main()
{
    fast_cin();

    getT()
    {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> queries(q);

        for (int i = 0; i < q; i++)
        {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution ob;
        ob.solve(n, queries);
    }
    return 0;
}