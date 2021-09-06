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
deque<int> rotate(deque<int> dq)
{
    int front = dq.front();
    dq.pop_front();
    dq.push_back(front);
    return dq;
}

// int max_sum(vector<int> A, int N)
// {
//     int maxS = INT32_MIN;
//     deque<int> dq;
//     for (int i = 0; i < N; i++)
//         dq.push_back(A[i]);

//     for (int i = 0; i < N; i++)
//     {
//         auto temp = rotate(dq);
//         int index = 0;
//         dq = temp;
//         int sum = 0;
//         while (!temp.empty())
//         {
//             sum+=(index++ * temp.front());
//             temp.pop_front();
//         }
//         maxS = max(sum, maxS);

//     }
//     return maxS;
// }

int getTotalSum(int A[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += A[i];
    return sum;
}
int max_sum(int A[], int N)
{
    int maxS = INT32_MIN;

    int currentSum = 0;
    for (int i = 0; i < N; i++)
    {
        currentSum += (i * A[i]);
    }
    int totalS = getTotalSum(A, N);
    maxS = max(maxS, currentSum);

    int lastIndex = N - 1;
    for (int i = 1; i < N; i++)
    {
        int newS = currentSum + totalS - A[lastIndex] * (N - 1) - A[lastIndex];
        maxS = max(maxS, newS);
        currentSum = newS;
        lastIndex--;
    }
    return maxS;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int A[4] = {8, 3, 1, 2};
    int n = 4;

    cout << max_sum(A, n) << endl;

    return 1;
}