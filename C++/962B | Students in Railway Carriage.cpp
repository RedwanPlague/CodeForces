#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 200005
 
int main()
{
   int a, b, n;
   cin>>n>>a>>b;
   string s;
   cin>>s;
 
   vector <int> df;
 
   int cont = 0;
   ll ans = 0;
 
   for(int i=0; i<n; i++)
   {
      if(i == n-1)
      {
         if(s[i] == '.')
            df.push_back(cont+1);
         else if(cont)
            df.push_back(cont);
      }
      else if(s[i] == '.')
         cont++;
      else
      {
         if(cont) df.push_back(cont);
         cont = 0;
      }
   }
 
   if(a < b)
      swap(a,b);
 
   for(int i=0; i<df.size(); i++)
   {
      //cout<<df[i]<<' ';
      int big = (df[i]-1)/2 + 1;
      if(a >= big)
      {
         ans += big;
         a -= big;
         df[i] -= big;
      }
      else
      {
         int small = df[i]/2;
         ans += min(a, small);
         a -= min(a, small);
         df[i] -= min(a, small);
         break;
      }
   }
 
   for(int i=0; i<df.size(); i++)
   {
      if(b >= df[i])
      {
         ans += df[i];
         b -= df[i];
      }
      else
      {
         ans += min(b, df[i]);
         b -= min(b, df[i]);
      }
   }
 
   cout<<ans<<endl;
 
   return 0;
}