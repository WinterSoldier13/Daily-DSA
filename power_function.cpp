#include<iostream>
using namespace std;


int power(int x, int y)
{
    int temp;
    if(y==0)
    {
        return 1;
    }
    temp = power(x,y/2); // Divide 2^16  to 2^8 and 2^8 ans so on...
    if(y%2==0)
    {
        return temp*temp;  //if its even just return 2^8 x 2^8
    }
    else
    {
        if(y>0)
        return x*temp*temp; // If odd like for 2^15 return 2x2^7x2^7

        else
        {
            return (temp*temp)/x;
        }
        
    }
    
}

int main()
{
    cout<<power(2,3)<<endl;
    return 0;
}