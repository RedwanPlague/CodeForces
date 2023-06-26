#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 1000000007
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   ll n, m, k;
   cin>>n>>m>>k;
 
   if(k < n)
   {
      cout<<k+1<<' '<<1<<endl;
      return 0;
   }
 
   if(k == n)
   {
      cout<<n<<' '<<2<<endl;
      return 0;
   }
 
   k -= n;
 
   ll row = n - k/(m-1);
   ll col = (row&1) ? (m - k%(m-1)) : (2 + k%(m-1));
 
   cout<<row<<' '<<col<<endl;
 
   return 0;
}
 