bool solve(string s0, string s1)
{
    if (s0.size() - s1.size() > 1)
        return false;

    int ptr1 = 0;
    int ptr2 = 0;
    int count = 0;

    while (ptr1 < s0.size() and ptr2 < s1.size())
    {
        while (s0[ptr1] == s1[ptr2])
        {
            ptr1++;
            ptr2++;
        }
        count++;
        if(count > 1)
            return 0;
        if(s0.size() == s1.size())
        {
            ptr1++;
            ptr2++;
        }
        else
        {
            if(s0.size() > s1.size())
                ptr1++;
            else
            {
                ptr2++;
            }
            
        }
    }
    return 1;
}