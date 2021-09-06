class Solution {
public:
void rotate(vector<int>& arr, int k) 
{

    vector<int> part1;
    vector<int> part2;
    
    if(arr.size()==0 or arr.size()==1 )
        return;
    
    if(arr.size()<k)
    {
        k = k-arr.size();
    }

    reverse(arr.begin(), arr.end());

    for(int i=0;i<k;i++)
    {
        part1.push_back(arr[i]);
    }
    for(int i=k;i<arr.size();i++)
    {
        part2.push_back(arr[i]);
    }
    int count = 0;
        reverse(part1.begin(),part1.end());
    reverse(part2.begin(),part2.end());
    for (auto x: part1)
    arr[count++] = x;
    for(auto x: part2)
    arr[count++] = x;

    for(auto x: arr)
    cout<<x<<endl;

    
}
};