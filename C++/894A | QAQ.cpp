#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   int cnt = 0;
   string s;
   cin>>s;
   for(int i=0; i<s.length(); i++)
   {
      if(s[i]!='Q')
         continue;
      for(int j=i+1; j<s.length(); j++)
      {
         if(s[j]!='A')
            continue;
         for(int k=j+1; k<s.length(); k++)
         {
            if(s[k]=='Q')
               cnt++;
         }
      }
   }
   cout<<cnt<<endl;
   return 0;
}