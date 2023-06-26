#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y[100005];
ll hc[100005];
ll hm[100005], aw[100005];
int main()
{
   ll i, n;
   cin>>n;
   for(i=0; i<n; i++) {
      scanf("%d %d", &x, &y[i]);
      hc[x]++;
      hm[i]=aw[i]=n-1;
   }
   for(i=0; i<n; i++) {
      hm[i]+=hc[y[i]];
      aw[i]-=hc[y[i]];
      cout<<hm[i]<<' '<<aw[i]<<endl;
   }
   return 0;
}