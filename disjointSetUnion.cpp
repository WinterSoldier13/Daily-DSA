#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> rank;
    vector<int> parent;

    void doUnion(int node1, int node2)
    {
        int parentOfNode1 = getParent(node1);
        int parentOfNode2 = getParent(node2);

        if (parentOfNode1 == parentOfNode2)
        {
            return;
        }
        else
        {
            int rankOfNode1 = rank[node1];
            int rankOfNode2 = rank[node2];

            if (rankOfNode1 == rankOfNode2)
            {
                if (node1 < node2)
                {
                    parent[node2] = node1;
                    rank[node1] += rank[node2];
                }
                else
                {
                    parent[node1] = node2;
                    rank[node2] += rank[node1];
                }
            }
            else
            {
                if (rankOfNode1 > rankOfNode2)
                {
                    parent[node2] = node1;
                    rank[node1] += rank[node2];
                }
                else
                {
                    parent[node1] = node2;
                    rank[node2] += rank[node1];
                }
            }
        }
    }
    int getParent(int node)
    {
        int curr = node;
        while (parent[node] != node)
        {
            node = parent[node];
        }
        parent[curr] = node;
        return parent[curr];
    }

    void makeSet(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

public:
    void solve(int n)
    {
        rank = vector<int>(n, 0);
        parent = vector<int>(n);
        makeSet(n);

        doUnion(1, 2);
        doUnion(3, 4);
        doUnion(5, 6);
        doUnion(3, 5);
        doUnion(8, 6);

        cout << getParent(0) << endl;
        cout << getParent(1) << endl;
        cout << getParent(2) << endl;
        cout << getParent(3) << endl;
        cout << getParent(4) << endl;
        cout << getParent(5) << endl;
        cout << getParent(6) << endl;
        cout << getParent(7) << endl;
        cout << getParent(8) << endl;
    }
};

int main()
{

    DisjointSet ob;
    ob.solve(9);
    return 0;
}