#include "solution.hpp"
using namespace std;

class RunLengthDecodedIterator {
    public:
    string str;
    int pointer;
    int maxL;
    RunLengthDecodedIterator(string s) 
    {
        string temp = "";
        string out = "";
        int ptr = 0;

        while (ptr < s.size())
        {

            while (isdigit(s[ptr]))
            {
                temp += s[ptr];

                ptr++;
            }
            int count = stoi(temp);
            while (count--)
            {
                out += s[ptr];
            }
            ptr++;
            temp = "";
        }
        str = out;
        pointer = -1;
        maxL = str.size();
        
    }

    string next() 
    {
        string s="";
        s+=str[++pointer];
        return s;
    }

    bool hasnext() 
    {
        return pointer<maxL-1;
    }
};