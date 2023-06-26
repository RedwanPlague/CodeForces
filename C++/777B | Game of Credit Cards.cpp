#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lb(u) lower_bound(m.begin(), m.end(), u)
#define ub(u) upper_bound(m.begin(), m.end(), u)
int main()
{
   int n, i;
   scanf("%d", &n);
   char a[n+1], b[n+1];
   scanf("%s", a);
   scanf("%s", b);
   vector <char> m;
   vector <char> :: iterator it;
   sort(a,a+n);
   for(i=0; i<n; i++) {
      m.pb(b[i]);
   }
   sort(m.begin(),m.end());
   int flick=n;
   for(i=0; i<n; i++) {
      it=lb(a[i]);
      if(it==m.end()) break;
      flick--;
      m.erase(it);
   }
   printf("%d\n", flick);
   m.clear();
   for(i=0; i<n; i++) {
      m.pb(b[i]);
   }
   sort(m.begin(),m.end());
   flick=0;
   for(i=0; i<n; i++) {
      it=ub(a[i]);
      if(it==m.end()) break;
      flick++;
      m.erase(it);
   }
   printf("%d", flick);
   return 0;
}