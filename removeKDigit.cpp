class Solution {
public:
string removeKdigits(string num, int k) {

    if(num.size()==k)
        return "0";
    int n=num.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        while(k>0&&!st.empty()&&st.top()>num[i])
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    
    while(!st.empty()&&k>0)
    {
        st.pop();
        k--;
    }
    string str;
    while(!st.empty()){
        str.push_back(st.top());
        st.pop();
    }
    int m=str.size();
    reverse(str.begin(),str.end());
    //cout<<"str is"<<str<<endl;
    
    int i=0,j=-1;
    while(str[i]=='0'){
        j=i;
        i++;
       
    }
    str=str.substr(j+1,m);
    if(str.size()==0)
        return "0";
        else
    return str;
}
};