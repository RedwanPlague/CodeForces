#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 10020
#define pb push_back
 
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
 
int change(int n)
{
    bool neg = (n < 0) ? 1 : 0;
    n = abs(n);
    for(int i=0; prime[i]<=sqrt(n+1); i++)
    {
        int sq = prime[i]*prime[i];
        while(n%sq == 0)
            n /= sq;
    }
    return (neg ? -n : n);
}
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    sieve();
    int n;
    cin>>n;
    int a[5001];
    map <int,int> mp;
 
    int mark = 1;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] == 0)
            continue;
        a[i] = change(a[i]);
        if(mp.find(a[i]) == mp.end())
            mp[a[i]] = mark++;
        a[i] = mp[a[i]];
    }
 
    int freq[5001];
    mark = 0;
    memset(freq, 0, sizeof(0));
    int ans[5001];
    memset(ans, 0, sizeof(ans));
 
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        mark++;
        for(int j=i; j<n; j++)
        {
            if(a[j] && freq[a[j]] != mark)
            {
                cnt++;
                freq[a[j]] = mark;
            }
            ans[cnt]++;
        }
    }
    ans[1] += ans[0];
 
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<' ';
    cout<<endl;
 
    return 0;
}