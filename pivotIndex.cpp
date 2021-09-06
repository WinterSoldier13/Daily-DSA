class Solution
{
public:
    int pivotIndex(vector<int> &arr)
    {
        if (arr.size() == 0)
            return -1;
        int l = arr.size();
        vector<int> left2right;
        vector<int> right2left;

        left2right.push_back(arr[0]);
        for (int i = 1; i < l; i++)
        {
            left2right.push_back(arr[i] + left2right[i - 1]);
        }
        reverse(arr.begin(), arr.end());
        right2left.push_back(arr[0]);
        for (int i = 1; i < l; i++)
        {
            right2left.push_back(arr[i] + right2left[i - 1]);
        }
        reverse(right2left.begin(), right2left.end());

        for (int i = 0; i < l; i++)
        {
            if (left2right[i] == right2left[i])
            {
                return i;
            }
        }
        return -1;
    }
};