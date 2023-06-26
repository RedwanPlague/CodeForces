#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, i, diff=0, j;
   vector <int> v;
   cin>>n;
   int a[n], b[n], p[n], bp[n+1];
   memset(bp,0,sizeof(bp));
   memset(p,0,sizeof(p));
   for(i=0; i<n; i++) cin>>a[i];
   for(i=0; i<n; i++) cin>>b[i];
   for(i=0; i<n; i++) {
      if(a[i]==b[i]) {
         p[i]=a[i];
         bp[a[i]]=1;
      }
      else v.push_back(i);
   }
   for(i=1; i<=n; i++) if(bp[i]==0) v.push_back(i);
   if(v.size()==2) p[v.front()]=v[1];
   else {
      if((a[v[0]]==v[2] && b[v[1]]==v[3]) || (b[v[0]]==v[2] && a[v[1]]==v[3])) {p[v[0]]=v[2]; p[v[1]]=v[3];}
      else {p[v[0]]=v[3]; p[v[1]]=v[2]; }
   }
   for(i=0; i<n; i++) printf("%d ", p[i]);
   return 0;
}