#include <bits/stdc++.h>
 
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 100010;
const int MOD = 1e9+7;
 
vector <ll> prime;
 
void sieve()
{
   bool mark[MX];
   memset(mark, 0, sizeof(mark));
   int limit = sqrt(MX + 1);
   mark[0] = mark[1] = 1;
   prime.pb(2);
   for(int i=3; i<MX; i+=2)
   {
      if(mark[i])
         continue;
      prime.pb(i);
      if(i>limit)
         continue;
      for(int j=i*i; j<MX; j+=2*i)
         mark[j] = 1;
   }
}
 
ll count_divisor(ll b)
{
    ll ans = 1LL;
    ll cnt;
    for(int i=0; i<prime.size() && prime[i]*prime[i] <= b; i++)
    {
        cnt = 0;
        while(b % prime[i] == 0)
        {
            b /= prime[i];
            cnt++;
        }
        if(cnt)
            ans *= (cnt+1);
    }
    if(b > 1)
        ans <<= 1;
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    sieve();
 
    ll b;
    cin >> b;
    cout << count_divisor(b) << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 