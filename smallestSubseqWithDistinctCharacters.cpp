class Solution {
public:
    string smallestSubsequence(string s) {
         if(s.size() == 0 or s.size() == 1)
        {
            return s;
        }
        
        unordered_map<char, int> hashmap;
        for (auto x : s)
        {
            hashmap[x]++;
        }
        unordered_set<char> track;

        stack<char> stack;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if(track.count(ch))
            {
                                hashmap[ch]--;

                continue;
            }
            if (stack.empty())
            {
                stack.push(ch);
                hashmap[ch]--;
                track.insert(ch);
                continue;
            }
            while (!stack.empty() and (stack.top()) > ch and (hashmap[stack.top()] > 0))
            {
                char top = stack.top();
                track.erase(top);
                stack.pop();
            }
            stack.push(ch);
            hashmap[ch]--;
            track.insert(ch);
        }
        string t = "";
        while (!stack.empty())
        {
            t += stack.top();
            stack.pop();
        }
        reverse(t.begin(), t.end());
        return t;
        
    }
};