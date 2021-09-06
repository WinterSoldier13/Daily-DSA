class Solution {
public:
bool isPowerOfFour(int num)
{
    if(num == 0)
    {
        return false;
    }
    int index = 0;
    bool digitFound = false;
    while (num != 0)
    {
        if (num & 1)
        {
            if (index % 2 != 0)
            {
                return false;
            }
            if(!digitFound)
            {
                digitFound = true;
            }
            else if(digitFound)
            {
                return false;
            }
        }
        num = num >> 1;
        index++;
    }
    return true;
}
};
