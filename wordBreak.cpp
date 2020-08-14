class Solution
{
public:
    unordered_map<string, int> mem;

    bool recurse(string str, unordered_map<string, int> dict)
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

            if (dict.find(sub) != dict.end() and recurse(later, dict))
            {
                return mem[str] = true;
            }
        }
        return mem[str] = false;
    }
    bool wordBreak(string s, vector<string> &B)
    {
        unordered_map<string, int> hashmap;
        for (auto x : B)
            hashmap[x] = 1;

        int l = s.size();

        int dp[l + 1];
        dp[0] = true;

        for (int i = 1; i <= l; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] and hashmap.find(s.substr(j, i - j)) != hashmap.end())
                {
                    dp[i] = true;
                    break;
                }
                else
                {
                    dp[i] = false;
                }
            }
        }
        return dp[l];
    }
};