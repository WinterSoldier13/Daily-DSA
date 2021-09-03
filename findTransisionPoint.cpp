int transitionPoint(int arr[], int n) {
    // code here
    int start = 0;
    int end = n-1;
    if(arr[0] == 1)
    {
        return 0;
    }
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        
        if(mid>0 and arr[mid] == 1 and arr[mid-1] == 0)
        {
            return mid;
        }
        else if( arr[mid] == 0 )
        {
            start = mid +1 ;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
    
}