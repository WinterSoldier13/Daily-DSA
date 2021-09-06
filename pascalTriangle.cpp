class Solution {
public:
    vector<vector<int>> generate(int n)
    {
    int count = 0;
    vector<vector<int>> out;

    if(n==0)
    return out;

    out.push_back(vector<int>{1});
    if(n==1)
      return out;
    vector<int> alpha{1,1};
    out.push_back(alpha);
    if(n==2)
    return out;

    for(int i=3;i<=n;i++)
    {
        vector<int> prevArr= out[out.size()-1];
        int prevL = prevArr.size();

        vector<int> temp(prevL+1, 0);
        temp[0] =1;
        temp[temp.size()-1] = 1;

        int j =1;
        int ptr1=0;
        int ptr2 = ptr1+1;
        while(ptr2<prevL)
        {
            temp[j++] = prevArr[ptr1++] + prevArr[ptr2++];
        }

        out.push_back(temp);
    }
    return out; 
    }
};