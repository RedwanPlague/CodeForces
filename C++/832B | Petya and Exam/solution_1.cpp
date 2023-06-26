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
   int n, i, j, lt,
   ls = s.length();
   cin>>n;
   while(n--)
   {
      cin>>t;
      lt = t.length();
      if(lt<ls-1)
         goto no;
      for(i=0; i<ls; i++)
         if(s[i]=='*')
            break;
      if(i==ls)
      {
         if(ls!=lt)
            goto no;
         for(j=0; j<ls; j++)
         {
            if(s[j]=='?')
            {
               if(!a[t[j]-'a'])
                  goto no;
            }
            else if(s[j]!=t[j])
               goto no;
         }
         goto yes;
      }
      for(j=0; j<i; j++)
      {
         if(s[j]=='?')
         {
            if(!a[t[j]-'a'])
               goto no;
         }
         else if(s[j]!=t[j])
            goto no;
      }
      for(; j<i+lt-ls+1; j++)
      {
         if(a[t[j]-'a'])
            goto no;
      }
      for(i++; i<ls; i++, j++)
      {
         if(s[i]=='?')
         {
            if(!a[t[j]-'a'])
                  goto no;
         }
         else if(s[i]!=t[j])
            goto no;
      }
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