class Solution {
public:
    bool isPalindrome(string s) 
    {
        string str="";
        for (char ch: s)
        {
            if(isalnum(ch))
                str+=ch;
        }
        
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        string temp = str;
        reverse(temp.begin(), temp.end());
        return temp==str;
        
        
    }
};