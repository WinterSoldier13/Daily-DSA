/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(vector<string> dict,string pattern)
{
    vector<string> out;
    int l = pattern.size();
    for(auto s: dict)
    {
        unordered_map<char, char> hashmap;
        unordered_map<char, char> hashmap2;
        for(int i=0;i<l;i++)
        {
            if(hashmap2.find(pattern[i]) != hashmap2.end())
            {
                continue;
            }
            hashmap[s[i]] = pattern[i];
            hashmap2[pattern[i]] = s[i];
        }
        
        string new_ = "";
        for(auto x: s)
        {
            new_+=hashmap[x];
        }
        if(new_ == pattern)
        {
            out.push_back(s);
        }
    }
    return out;
}