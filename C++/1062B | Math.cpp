#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 1050;
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
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
 
    if(n == 1)
    {
        cout << 1 << " " << 0 << endl;
        return 0;
    }
 
    sieve();
 
    int mx = 1;
    ll num = 1LL;
 
    set<int> st;
 
    for(int i=0; i<prime.size(); i++)
    {
        int cnt = 0;
        while(n % prime[i] == 0)
        {
            n /= prime[i];
            cnt++;
        }
        if(cnt)
        {
            mx = max(mx,cnt);
            st.insert(cnt);
            num *= prime[i];
        }
    }
 
    if(n > 1)
    {
        mx = max(mx,1);
        num *= n;
        st.insert(1);
    }
 
    int pos = 0;
    while((1LL<<pos) < mx)
        pos++;
 
    cout << num << " " << 1 + pos - (st.size() == 1 && ((1LL<<pos) == mx)) << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 