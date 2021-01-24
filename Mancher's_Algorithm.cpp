#include<bits/stdc++.h>
using namespace std;
int Manchers(string str)
{
     int n=str..length();
     string s='$';
     for(int i=0;i<n;i++){
         s+='#';
         s+=str[i];
     }
     s+="#@";
     int c=0,r=0;
     int dp[s.length()];
     for(int i=1;i<(s.length()-1);i++)
     {
        int mirr=2*c-i;
        if(i<r){
            dp[i]=min(r-i,dp[mirr]);
        }
        while(s[i+(1+dp[i])]==s[i-(1+dp[i])]){
            dp[i]++;
        }
        if(i+dp[i] > r)
        {
            c=i; r=i+dp[i];
        }
     }
     int ans=0;
     for(int i=0;i<s.length();i++){
         ans=max(ans,dp[i]);
     }
     return ans;
}

int main()
{
   string str="ACBCACB";
   cout<<"MaxLength = "<<Manchers(str);
}