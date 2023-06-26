#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 100010;
const int MOD = 1e9+7;
 
#define pb push_back
 
vector<ll> prime;
 
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
 
ll p_div(const ll N)
{
    for(int i=0; i<prime.size() && prime[i]*prime[i] <= N; i++)
    {
        if(N % prime[i] == 0)
        {
            return prime[i];
        }
    }
    return N;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    sieve();
 
    ll N;
    cin >> N;
 
    if(N % 2 == 0)
    {
        cout << N / 2 << endl;
        return 0;
    }
 
    N -= p_div(N);
 
    cout << 1 + N/2 << endl;
 
    return 0;
}