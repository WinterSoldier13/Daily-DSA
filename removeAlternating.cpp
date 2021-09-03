#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>


vector<int> print_subsequence(vector<int> &arr, int* up, int* down, int n, int m, int ind)
{
    int f_up = 0;
    int f_down = 0;
    vector<int> v;

    if (m == up[ind]) {
        f_up = 1;
    }
    else {
        f_down = 1;
    }
    vector<int> indexes;
    v.push_back(arr[ind]);
    indexes.push_back(ind);
    for (int i = ind - 1; i >= 0; i--) {
        if (m == 1) {
            break;
        }
        if (f_down) {
            if (up[i] + 1 == m) {
                v.push_back(arr[i]);
                indexes.push_back(i);
                m = up[i];
                f_down = 0;
                f_up = 1;
            }
        }
        else if (f_up) {
            if (down[i] + 1 == m) {
                v.push_back(arr[i]);
                indexes.push_back(i);
                m = down[i];
                f_down = 1;
                f_up = 0;
            }
        }
    }
    unordered_set<int> restricted;
    for(auto x: indexes)
    {
        restricted.insert(x);
    }
    vector<int> out;
    for(int i = 0; i<arr.size(); i++)
    {
        if(restricted.count(i) == 0)
        out.push_back(arr[i]);
    }

    return out;
}

vector<int> find_length(vector<int> &arr)
{
    int n = arr.size();

    int up[n];
    int down[n];

    for (int i = 0; i < n; i++) {
        up[i] = 1;
        down[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                up[i] = max(up[i], down[j] + 1);
            }
            else if (arr[i] < arr[j]) {
                down[i] = max(down[i], up[j] + 1);
            }
        }
    }

    int m = 0;
    int ind = 0;

    for (int i = 0; i < n; i++) {
        int temp = max(up[i], down[i]);
        if (temp > m) {
            m = temp;
            ind = i;
        }
    }

    return print_subsequence(arr, up, down, n, m, ind);
}

void printArr(vector<int> &arr)
{
    for(auto x : arr)
    cout<<x<<" ";
    cout<<endl;
}

int solve(string s)
{
    vector<int> arr;
    for( auto x: s)
    {
        arr.push_back(x-'0');
    }

    int count = 0;

    if(arr.size() == 1 or arr.size() == 0)
    {
        return arr.size();
    }

    while(true)
    {
        // printArr(arr);
        if(arr.size() == 0)
        {
            break;
        }
        if(arr.size() == 1)
        {
            count++;
            break;
        }
        arr = find_length(arr);
        count++;

    }

    return count;

}

int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);

    string s = "11010111";
    cout<<solve(s)<<endl;
<<<<<<< HEAD
}
=======
}
>>>>>>> 17cf60c95e6f4c02d323dfb4aa9b9d8fc29f1408
