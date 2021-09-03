bool solve(string typed, string target) 
{
    if(typed == target)
    {
        return true;
    }
    int l1 = typed.size();
    int l2 = target.size();

    int ptr1 = 0;
    int ptr2 = 0;

    while(ptr1<l1 and ptr2<l2)
    {
        while(ptr1<l1 and ptr2<l2 and typed[ptr1] == target[ptr2])
        {
            ptr1++;
            ptr2++;
        }
        while(ptr1<l1 and typed[ptr1] == target[ptr2-1])
        {
            ptr1++;
        }
        if(ptr1<l1 and typed[ptr1]!=target[ptr2]) return 0;
    }
    if(ptr2<l2) return 0;
    while(ptr1<l1)
    {
        if(typed[ptr1] != target[ptr2-1])  return 0;
        ptr1++;
    }

    return 1;
}

