#include <iostream>
using namespace std;
int det[5][5];
int mat[13][5];

void detonate(int r)
{
    for (int i = r; i > r - 5 && i >= 0; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            det[r - i][j] = 0;
            if (mat[i][j] == 2)
            {
                det[r - i][j] = 2;
                mat[i][j] = 0;
            }
        }
    }
}

void undet(int r)
{
    for (int i = r; i > r - 5 && i >= 0; i--)
        for (int j = 0; j < 5; j++)
        {
            if (det[r - i][j] == 2)
                mat[i][j] = 2;
        }
}
void func(int n, int pos, int c, int &max)
{
    if (pos > 4 || pos < 0 || c < 0)
        return;

    if (mat[n][pos] == 2)
        c -= 1;
    else if (mat[n][pos] == 1)
        c += 1;

    if (n == 0)
    {
        if (c > max)
            max = c;
        return;
    }
    else
    {
        func(n - 1, pos + 1, c, max);
        func(n - 1, pos - 1, c, max);
        func(n - 1, pos, c, max);
    }
}
int main()
{
    int t;
    cin >> t;
    int count = 1;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> mat[i][j];
        int max = -1, c;
        for (int j = 0; j < 5; j++)
            mat[n][j] = 0;
        mat[n][2] = 3;
        for (int j = n; j >= 5; j--)
        {
            c = -1;
            detonate(j - 1);
            func(n, 2, 0, c);
            if (c > max)
                max = c;
            undet(j - 1);
        }
        if (max < 0)
            max = -1;
        cout << "#" << count << " " << max << endl;
        count++;
    }
}
