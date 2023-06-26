#include <bits/stdc++.h>
 
#define br '\n'
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const int MX = 4000;
const int MOD = 1000000007;
 
vector <int> prime;
 
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
 
    sieve();
 
    int n;
    cin >> n;
    int a[300005], gcd = 0;
 
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        gcd = __gcd(gcd, a[i]);
    }
 
    if(gcd > 1)
        for(int i=0; i<n; i++)
            a[i] /= gcd;
 
    int mx = 0;
 
    for(int p=0; p<prime.size(); p++)
    {
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i]%prime[p] == 0)
            {
                cnt++;
                while(a[i]%prime[p] == 0)
                    a[i] /= prime[p];
            }
        }
        mx = max(mx, cnt);
    }
 
    map <int,int> mp;
 
    for(int i=0; i<n; i++)
        if(a[i] > 1)
            mp[a[i]]++;
 
    for(map<int,int> :: iterator it = mp.begin(); it != mp.end(); it++)
        mx = max(mx,it->second);
 
    if(mx < 1)
        mx = n+1;
 
    cout << n - mx << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 