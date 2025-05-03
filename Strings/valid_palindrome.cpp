class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string a,b;
        if(n==1)
         return true;
        for(int i=0;i<n;i++)
        {
            if(s[i]>=65 && s[i]<=90)
                a+=(s[i]+32);
            else if(s[i]>=97 && s[i]<=122)
                a+=s[i];
            else if(s[i]>='0'&&s[i]<='9')
                a+=s[i];
        }
        for(int i=a.size()-1;i>=0;i--)
         b+=a[i];
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
             return false;
        }
        return true;
    }
};
