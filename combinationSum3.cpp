class Solution {
public:

vector<vector<int>> mothership;
int K;
int N;

int findSum(vector<int> &arr)
{
    int sum_ = 0;
    for (auto x : arr)
    {
        sum_ += x;
    }
    return sum_;
}

void recurse(vector<int> &arr, int index, vector<int> temp)
{
    if (index == arr.size() - 1)
    {
        if (temp.size() == K and findSum(temp) == N)
            mothership.push_back(temp);

        temp.push_back(arr[index]);

        if (temp.size() == K and findSum(temp) == N)
            mothership.push_back(temp);

        return;
    }
    if (temp.size() <= K and findSum(temp) <= N)
        recurse(arr, index + 1, temp);

    temp.push_back(arr[index]);
     if (temp.size() <= K and findSum(temp) <= N)
        recurse(arr, index + 1, temp);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    K = k;
    N = n;
    mothership.clear();

    vector<int> arr{1,2,3,4,5,6,7,8,9};
    vector<int> temp;
    int index = 0;

    recurse(arr, 0, temp);

    return mothership;
}
};