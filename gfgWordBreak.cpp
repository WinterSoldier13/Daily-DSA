    #include <bits/stdc++.h>
    #include <stdio.h>
    using namespace std;
    #define ll long long int
    unordered_map<string, int> mem;

    bool recurse(string str, unordered_set<string> &dict)
    {
        if (mem.find(str) != mem.end())
        {
            return mem[str];
        }


        if (str.size() == 0)
        {
            return true;
        }

        for (int i = 1; i <= str.size(); i++)
        {
            string sub = str.substr(0, i);
            string later = str.substr(i, str.size() - i);

            cout<<sub<<" "<<later<<endl;

            if (dict.find(sub) != dict.end() and recurse(later, dict))
            {
                return mem[str] = true;
            }
        }
        return mem[str] = false;
    }
    int wordBreak(string s, unordered_set<string> &hashmap)
    {
        return recurse(s, hashmap);
    }

    int main()
    {
        int t;
        scanf("%d", &t);

        while (t--)
        {
            int n;
            cin >> n;
            unordered_set<string> hashset;
            for (int i = 0; i < n; i++)
            {
                string temp;
                cin >> temp;
                hashset.insert(temp);
            }
            string s;
            cin >> s;

            cout << wordBreak(s, hashset) << endl;
        }
    }