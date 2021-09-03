class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        int ptr = 0;
        
        for(int i=0;i<A.size();i++)
        {
            if(A[i]%2==0)
            {
                // swap(A[i], A[ptr++]);
                int temp = A[i];
                A[i] = A[ptr];
                A[ptr++] = temp;
            }
        }
        return A;
        
    }
};