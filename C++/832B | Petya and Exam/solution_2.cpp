#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios_base::sync_with_stdio(false);
 string s, t;
 cin>>t>>s;
 int *a = (int*)calloc(26,sizeof(int));
 for(auto i: t)
      a[i-'a'] = 1;
   int n, i, j, lt, jl, jr,
   ls = s.length();
   cin>>n;
   while(n--)
   {
      cin>>t;
      lt = t.length();
      if(lt<ls-1)
         goto no;
      for(i=0; i<ls; i++)
      {
         if(s[i]>='a' && s[i]<='z')
         {
            if(s[i]!=t[i])
               goto no;
            else continue;
         }
         else if(s[i]=='?')
         {
            if(a[t[i]-'a']!=1)
               goto no;
            else continue;
         }
         else if(s[i]=='*')
            break;
      }
      jl = i;
      //cout<<jl<<endl;
      for(i=ls-1, j=lt-1; i>=0 && j>=0; i--, j--)
      {
         if(s[i]>='a' && s[i]<='z')
         {
            if(s[i]!=t[j])
               goto no;
            else continue;
         }
         else if(s[i]=='?')
         {
            if(a[t[j]-'a']!=1)
               goto no;
            else continue;
         }
         else if(s[i]=='*')
            break;
      }
      jr = j;
      //cout<<jr<<endl;
      if(jl==ls)
      {
         if(ls<lt)
            goto no;
         else
            goto yes;
      }
      for(i=jl; i<=jr; i++)
         if(a[t[i]-'a']!=0)
            goto no;
      goto yes;
      no:
         cout<<"NO"<<endl;
         goto theend;
      yes:
         cout<<"YES"<<endl;
      theend: {}
   }
 return 0;
}