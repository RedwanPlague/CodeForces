#include <bits/stdc++.h>
using namespace std;
int main()
{
   string s, t;
   int *a = (int*)calloc(26,sizeof(int));
   int *b = (int*)calloc(26,sizeof(int));
   cin>>s>>t;
   int i, j, mx, qs=0, suit=0,
   ls = s.length(),
   lt = t.length();
   for(i=0; i<ls; i++)
   {
      if(s[i]=='?')
         qs++;
      else
         a[s[i]-'a']++;
   }
   for(i=0; i<lt; i++)
      b[t[i]-'a']++;
   for(i=0; ; i++)
   {
      mx = 0;
      for(j=0; j<26; j++)
         mx += max(0, i*b[j]-a[j]);
      if(mx<=qs)
         suit = i;
      else
         break;
   }
   for(i=0; i<26; i++)
      b[i] = max(0, suit*b[i]-a[i]);
   j = 0;
   t = "";
   for(i=0; i<26; i++)
      while(b[i]--)
         t += i+'a';
   lt = t.length();
   //cout<<t<<endl;
   for(i=0, j=0; i<ls && j<lt; i++)
      if(s[i]=='?')
         s[i] = t[j++];
   for(; i<ls; i++)
      if(s[i]=='?')
         s[i] = 'a';
   cout<<s<<endl;
   return 0;
}