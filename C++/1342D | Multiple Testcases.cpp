#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1000000007
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define invmod(x) bigmod(x,MOD-2)
#define br '\n'
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
ll bigmod(ll base, ll pw)
{
 ll ret = 1;
 while(pw)
 {
  if(pw&1)
   ret = ret*base %MOD;
  base = base*base %MOD;
  pw >>= 1;
 }
 return ret;
}
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
 int n, k;
 while(cin >> n >> k)
 {
  int b;
  vi a(k+1);
  for(int i=0; i<n; i++)
  {
   cin >> b;
   a[b]++;
  }
  vi m(k+1);
  for(int i=1; i<=k; i++)
   cin >> m[i];
 
  vector<vi> ans;
  int which = 0;
  for(int i=k; i>0; i--, which = (m[i] == m[i+1] ? max(0,which-1) : 0))
  {
   int take = 0;
   while(take < a[i])
   {
    if(ans.size() <= which)
     ans.emplace_back();
    while(take < a[i] && ans[which].size() < m[i])
    {
     ans[which].push_back(i);
     take++;
    }
    which++;
   }
  }
 
  cout << ans.size() << '\n';
  for(auto &v: ans)
  {
   cout << v.size();
   for(auto &x: v)
    cout << ' ' << x;
   cout << '\n';
  }
 }
 
 return 0;
}