class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        if (numRows == 0)
        {
            return "";
        }
        vector<vector<char>> arr(numRows);

        int start = 0;
        int end = numRows - 1;
        int c = 0;
        int index = 0;

        for (auto ch : s)
        {
            if (index > end)
            {
                index = end - 1;
                c++;
            }
            else if (index < start)
            {
                index = start + 1;
                c++;
            }

            if (c % 2 == 0)
            {
                arr[index++].push_back(ch);
            }
            else
            {
                arr[index--].push_back(ch);
            }
        }
        string __word__ = "";
        for (auto x : arr)
        {
            for (auto c : x)
            {
                cout << c << " ";
                __word__ += c;
            }
            cout << endl;
        }
        return __word__;
    }
};