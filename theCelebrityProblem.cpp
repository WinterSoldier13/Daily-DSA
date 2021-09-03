// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    int found = -1;
    for(int i=0;i<n;i++)
    {
        int isCleb = 1;
        for(int j=0;j<n;j++)
        {
            if(M[i][j] == 1)
            {
                isCleb = 0;
                break;
            }
        }
        if(isCleb)
        {
            for(int k=0;k<n;k++)
            {
                if(k == i)
                {
                    continue;
                }
                if(M[k][i] == 0)
                {
                    isCleb = 0;
                    break;
                }
            }
            if(isCleb){
            found = i;
            break;}
        }
    }
    return  found;
}