#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int, int>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> hashmap{0, 0};
    

        for (auto x : s)
        {
            hashmap[x - '0']++;
        }

        // cout<<hashmap[0]<<" -- "<<hashmap[1]<<endl;
        int special = n / k;

        if (hashmap[0] % special != 0 or hashmap[1] % special != 0)
        {
            cout << "IMMPOSSIBLE" << endl;
            continue;
        }

        int zeroL = hashmap[0] / special;
        int oneL = hashmap[1] / special;

        s = "";
        for (int i = 0; i < zeroL; i++)
        {
            s += to_string(0);
        }
        for (int i = 0; i < oneL; i++)
        {
            s += to_string(1);
        }
        // cout<<"First Part "<<s<<endl;
        vector<string> arr{s};
        for(int i=1;i<special;i++)
        {
            string temp = arr[i-1];
            reverse(temp.begin(), temp.end());
            arr.push_back(temp);
        }

        string out = "";
        for(auto x: arr)
        {
            out+=x;
        }
        if(out=="")
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<out<<endl;
    }
}
