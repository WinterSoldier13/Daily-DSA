
// DO inorder
vector<int> mergeSortedArray()
{
    vector<int> out;
    
    int l1 = arr1.size();
    int l2 = arr2.size();
    
    int i=0;
    int j =0 ;
    
    while(i<l1 or j<l2)
    {
        if(arr1[i]<=arr2[j])
        {
            out.push_back(arr1[i]);
            i++;
        }
        else
        {
            out.push_back(arr2[j]);
            j++;
        }
    }
    while(i<l1)
    {
        out.push_back(arr1[i++]);
    }
    while(j<l2)
    {
        out.push_back(arr2[j++]);
    }
    
    return out;
    
    
}