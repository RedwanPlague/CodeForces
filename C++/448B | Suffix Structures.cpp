#include <bits/stdc++.h>
using namespace std;
int main()
{
   string s, t;
   cin>>s>>t;
   int ls = s.length(),
   lt = t.length();
   int *a = (int*)calloc(26,sizeof(int));
   for(auto i: s)
      a[i-'a']++;
   for(auto i: t)
      a[i-'a']--;
   for(int i=0; i<26; i++)
   {
      if(a[i]<0)
      {
         puts("need tree");
         return 0;
      }
   }
   if(ls==lt)
   {
      puts("array");
      return 0;
   }
   int j = 0;
   for(int i=0; i<ls; i++)
   {
      if(s[i]==t[j])
         j++;
   }
   if(j==lt)
      puts("automaton");
   else
      puts("both");
 return 0;
}