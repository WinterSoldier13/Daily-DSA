#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

// Window String



bool checkOcc(string s, string t)
{
     unordered_map<char,int> map;
     for (char ch: s)
     {
          map[ch]+=1;
     }
     unordered_map<char,int> map2;
     for(char ch: t)
     {
          map2[ch]+=1;
     }
     bool flag = true;

     for(char ch:t)
     {
          if (map[ch]<map2[ch])
          {
               return false;
          }
     }
     return flag;
}

 
string windowString(string s, string t)
{
     if(t.size()>s.size())
     {
          return "";
     }
     int l = s.size();
     int left =0;
     int right =0;
     int min_len=INT32_MAX;
     string out="";
     bool control = true;

     while(right<l)
     {
          if(checkOcc(s.substr(left,right),t))
          {
               string sol = s.substr(left,right);
               int l2 = sol.size();
               if(l2<min_len)
               {
                    min_len = l2;
                    out = sol;

               }
               while(checkOcc(s.substr(left+1,right),t) and left<=right)
               {
                    left++;
               }
          }
          right++;

     }
     return out;

}  

int main()
{
     string s ="RIwC2cUoT5syRNnLP0Ch0RstnOZyekrE46XhLAwnLEokC6DcHSEj0QBmZiKf7INnb2JNlEzpZPdD3G4vmXms6pdnQy8aRMT4Z3jIvOdVffVBQ2ccLtsJu5PMLIe4WEBkP4J578EbuXgdRWGuAlhKpjYIIXNp97NdE9E8kKlgTeUPiij8YFcl8YXLdEf5bxQgZd7EQdgcCwutgcigN3F3aMF6F44hT5mGBoArDiPJsRb4xtl9x6G9kZobja7oTOBYlJnHduihoRtwNlMChWb2UxRizYll4y61sio6858FU0p1IH3IUGtH1dbE5AjHCKXswpa9X6kXkCnkKwTyfk0z4iXbFLOH8h3dvYmbhXiL310wTa7g8t2Spu9z5OfriQKIObOmJZZqrNtLNtFIsIHrmxZvcCcIq7EOI16FTBc2I1tQcIYX7e1goL25f69jVcy2rSo4TjaDXBa5aAZyydH5gILyTi6Cm9JRmMl7uj1FmT7TOxulqj5okO016GsRX2HIgkCLcChIZimrXaOrgYqWtfcUlLLyHPSv9DYaVsGiWs5bLip05SB62vC3mIkQ6CIzxS2SbzsFnB8eU8Cv7SnAoLrfKtQ6fScHGFYI2UMcui9cPM52wMncruQa4SCl4baSsudE9uEutclT6rUzfohahohKf02tRsL5GIHBPcZlDh5729O40aT0bfRuvXckMfaXL80STWOvxQkUisDvaG4tvn7JL73guzDU7Jy8m5sH78faLCaRm9TsUx1SDG1dZ0dWoB5WkT1LJY6XgntKmurdwP9FboQORy9aTwG3ho7VH0ztUeEJMN4Pl6QtWGyCObhp5bptdhYeEQp1it";
     string t ="cPZJznw814NwfiVJVLUCClKYnA9jCDdtE9S6sQmBuytNeSb9f4DttdWmqlDPYx";

     // cout<<checkOcc("XYZADSD","DXYD")<<endl;

     cout<<windowString(s,t)<<endl;
     // cout<<s.substr(1,3)<<endl;

     return 0;
}