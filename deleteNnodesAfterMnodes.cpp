#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void linkdelete(struct Node *head, int M, int N)
{
    Node *ptr1 = head, *ptr2;
    int a, b;
    while (ptr1)
    {
        a = M - 1;
        while (ptr1 and a--)
        {
            ptr1 = ptr1->next;
        }
        b = N;
        if (ptr1 == NULL)
            return;
        ptr2 = ptr1->next;
        while (ptr2 and b)
        {
            b--;
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr2;
        ptr1 = ptr1->next;
    }
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    return 1;
}