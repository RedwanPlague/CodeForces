#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   string s;
   int cur = 'a';
 
   cin>>s;
   int l = s.length();
 
   for(int i=0; i<l; i++)
   {
      if(s[i] <= cur)
      {
         s[i] = cur++;
      }
      if(cur > 'z')
         break;
   }
 
   if(cur > 'z')
      cout<<s<<endl;
   else
      cout<<-1<<endl;
 
   return 0;
}
 