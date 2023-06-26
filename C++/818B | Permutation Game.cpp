#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
 
int main()
{
   int n, m, i;
   cin>>n>>m;
   int a[n+1], b[m], taken[n+1];
   int place;
   memset(a,-1,sizeof(a));
   memset(taken,0,sizeof(taken));
   for(i=0; i<m; i++) cin>>b[i];
   for(i=0; i<m-1; i++) {
      place = b[i+1]-b[i];
      if(place<=0) place+=n;
      if((a[b[i]]!=-1 || taken[place]==1) && a[b[i]]!=place) {
         puts("-1");
         return 0;
      }
      a[b[i]]=place;
      taken[place]=1;
   }
   vector <int> v;
   vector <int> :: iterator it;
   for(i=1; i<=n; i++) if(taken[i]!=1) v.push_back(i);
   it=v.begin();
   for(i=1; i<=n; i++) {
      if(a[i]==-1) {
         a[i]=*it;
         it++;
      }
   }
   for(i=1; i<=n; i++) {
      if(a[i]==-1) {
         puts("-1");
         return 0;
      }
   }
   for(i=1; i<=n; i++) printf("%d ", a[i]);
   return 0;
}