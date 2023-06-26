#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 101
 
int main()
{
   ll n;
   cin>>n;
   n--;
   ll ans = 0;
   int pos = 0;
   while(n>>pos)
   {
      if(n&(1LL<<pos))
         ans += ((n>>(pos+1)) + 1) * (1LL<<pos);
      else
         ans += (n>>(pos+1)) * (1LL<<pos);
      pos++;
   }
 
   cout<<ans<<endl;
 
   return 0;
}
 
 