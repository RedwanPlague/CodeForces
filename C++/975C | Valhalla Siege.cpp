#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 1000000007
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n, q;
   ll k;
   cin>>n>>q;
 
   vector <ll> a(n);
   for(int i=0; i<n; i++)
      cin>>a[i];
 
   for(int i=1; i<n; i++)
      a[i] += a[i-1];
 
   ll extra = 0;
 
   while(q--)
   {
      cin>>k;
      int who = upper_bound(a.begin(), a.end(), k + extra) - a.begin();
      extra += k;
      if(who == n)
      {
         who = 0;
         extra = 0;
      }
      cout<<n - who<<'\n';
   }
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 