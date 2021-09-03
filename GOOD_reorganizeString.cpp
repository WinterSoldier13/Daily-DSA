class Solution {
public:

    string trim(string s)
    {
        string temp ="";
        for(char ch :s)
        {
            if(ch!=' ')
            temp+=ch;
        }
        return temp;
    }
    
    string reorganizeString(string s) 
    {
        int len = s.length();
    char rand = s[0];

    set<char> set_;


    map<char,int> freq;
    for(char ch: s)
    {
        freq[ch]+=1;
        set_.insert(ch);
    }

    vector<char> temp{'#'};
    char temp_storage=' ';

    while(temp.size()<=len)
    {
        int l = temp.size();
        int highPrior = 0;
        char highChar = ' ';

        for( char ch : set_)
        {
            if(freq[ch]>highPrior)
            {
                highPrior = freq[ch];
                highChar = ch;
            }
        }
        freq[highChar]--;
        freq[highChar] *=-1;
        freq[temp_storage]*=-1;
        temp_storage = highChar;
        temp.push_back(highChar);

    }
    string result="";
    for(char cha: temp)
    {
        result+=cha;
    }
    result = result.substr(1,result.length());
        result = trim(result);
    if(result.length()==len)
    return result;

    return "";
        
        
    }
};