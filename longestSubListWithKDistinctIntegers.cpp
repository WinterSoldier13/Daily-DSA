int solve(int k, vector<int>& arr) 
{
    if(k == 0)  return 0;
    if(arr.size() == 0 or arr.size()==1)
        return arr.size();

    int l = arr.size();
    unordered_map<int, int> hashmap;
    int ptr1 = 0;
    int ptr2 = 0;
    int ans = 0;

    while(ptr2<l)
    {
        while(hashmap.size() < k and ptr2<l)
        {
            hashmap[arr[ptr2]]++;
            ptr2++;
        }
        while(hashmap.find(arr[ptr2]) != hashmap.end() and ptr2<l)
        {
            hashmap[arr[ptr2]]++;
            ptr2++;
        }

        ans = max(ans, ptr2-ptr1);
        while(hashmap.size() == k and ptr1<ptr2)
        {
            hashmap[arr[ptr1]]--;
            if(hashmap[arr[ptr1]] == 0)
            {
                hashmap.erase(arr[ptr1]);
            }
            ptr1++;
        }
    }

    return ans;
}