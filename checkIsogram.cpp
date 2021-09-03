bool isIsogram(string s)
{
    unordered_map<char, int> hashmap;
    
    for(auto x: s)
    hashmap[x]++;
    
    for(auto it = hashmap.begin(); it!=hashmap.end();it++)
    {
        if(it->second > 1)
        {
            return 0;
        }
    }
    return 1;
}