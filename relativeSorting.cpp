class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
         int n, m;
        n=arr1.size();
        m = arr2.size();

        
        unordered_set<int> track;


        vector<int> out(n,0);

        unordered_map<int, int> hashmap;

        for(auto x: arr1)
        {
            hashmap[x]++;
        }
        int index = 0;

        for(int i=0;i<arr2.size();i++)
        {
            int curr = arr2[i];
            bool flag = false;

            while(hashmap[curr]--)
            {
                flag = true;
                out[index++] = curr;
            }
            if(flag)
            track.insert(curr);
        }

        vector<int> leftover;
        for(auto x: arr1)
        {
            if(track.find(x) == track.end())
            leftover.push_back(x);
        }
        sort(leftover.begin(), leftover.end());

        for(auto x: leftover)
        {
            out[index++] = x;
        }
        for(auto x: out)
        cout<<x<<" ";
        
        cout<<endl;
        return out;
    }
};