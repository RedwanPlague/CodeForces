#include <bits/stdc++.h>
using namespace std;
map <int,int> mp;
int main()
{
   int n, color;
   cin>>n;
   while(n--)
   {
      cin>>color;
      mp[color]++;
   }
   int m, maxb = -1, maxc = -1;
   cin>>m;
   int *b = new int[m];
   int *c = new int[m];
   for(int i=0; i<m; i++)
   {
      cin>>b[i];
      maxb = max(maxb,mp[b[i]]);
   }
   for(int i=0; i<m; i++)
   {
      cin>>c[i];
      if(mp[b[i]]==maxb)
      {
         maxc = max(maxc,mp[c[i]]);
      }
   }
   for(int i=0; i<m; i++)
   {
      if(mp[b[i]]==maxb && mp[c[i]]==maxc)
      {
         cout<<i+1<<endl;
         break;
      }
   }
   delete b;
   delete c;
   return 0;
}
 